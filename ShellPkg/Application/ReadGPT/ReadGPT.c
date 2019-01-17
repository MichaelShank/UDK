#include <Uefi.h>
#include <Base.h>
#include <Library/UefiLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/PrintLib.h>
#include <Protocol/DiskIo.h>
#include <Protocol/BlockIo.h>
#include <Protocol/DevicePath.h>
#include <Protocol/DevicePathToText.h>
#include <Uefi/UefiGpt.h>
#include <Library/DevicePathLib.h>

EFI_STATUS EFIAPI UefiMain(IN EFI_HANDLE ImageHandle, 
                           IN EFI_SYSTEM_TABLE *SystemTable)
{
    EFI_STATUS Stauts;
    UINTN HandleIndex, HandleCount;
    EFI_HANDLE *DiskControllerHandles = NULL;
    EFI_DISK_IO_PROTOCOL *DiskIo;       

    //
    Stauts = gBS->LocateHandleBuffer(ByProtocol, &gEfiDiskIoProtocolGuid, NULL, &HandleCount, &DiskControllerHandles);
    if(!EFI_ERROR(Stauts))
    {
        CHAR8 gptHeaderSector[512];
        EFI_PARTITION_TABLE_HEADER* gptHeader = (EFI_PARTITION_TABLE_HEADER*) gptHeaderSector;
        for(HandleIndex = 0; HandleIndex < HandleCount; HandleIndex++)
        {
            //Open EFI_DISK_IO_PROTOCOL
            Stauts = gBS->HandleProtocol(DiskControllerHandles[HandleIndex], &gEfiDiskIoProtocolGuid, (VOID**)&DiskIo);

            if(!EFI_ERROR(Stauts))
            {
                EFI_DEVICE_PATH_PROTOCOL *DiskDevicePath;
                EFI_DEVICE_PATH_TO_TEXT_PROTOCOL *Device2TextProtocol = 0;
                CHAR16* TextDevicePath = 0;
                //1. OpenEFI_DEVICE_PATH_PROTOCOL
                Stauts = gBS->OpenProtocol(DiskControllerHandles[HandleIndex], &gEfiDevicePathProtocolGuid, (VOID**)&DiskDevicePath, ImageHandle, NULL, EFI_OPEN_PROTOCOL_GET_PROTOCOL);

                if(!EFI_ERROR(Stauts))
                {
                    if(Device2TextProtocol == 0)
                        Stauts = gBS->LocateProtocol(&gEfiDevicePathToTextProtocolGuid, NULL, (VOID**)&Device2TextProtocol);

                    //2. Use EFI_DEVICE_PATH_PROTOCOL to get device path
                    TextDevicePath = Device2TextProtocol->ConvertDevicePathToText(DiskDevicePath, TRUE, TRUE);
                    Print(L"%s\n",TextDevicePath);
                    Print(L"%s\n",TextDevicePath);//Git Test
                    Print(L"%s\n",TextDevicePath);//Git Test23
                    //Print(L"%d\n", Device2TextProtocol->ConvertDevicePathToText);
                    if(TextDevicePath)
                        gBS->FreePool(TextDevicePath);
                    
                    //3. turn off EFI_DEVICE_PATH_PROTOCOL
                    Stauts = gBS->CloseProtocol(DiskControllerHandles[HandleIndex], &gEfiDevicePathProtocolGuid, ImageHandle, NULL);

                }
            }
            // {
                EFI_BLOCK_IO_PROTOCOL* BlockIo = *(EFI_BLOCK_IO_PROTOCOL**)(DiskIo + 1);
                EFI_BLOCK_IO_MEDIA* Media = BlockIo->Media;
                //Read the NO.1
                Stauts = DiskIo->ReadDisk(DiskIo, Media->MediaId, 512, 512, gptHeader);
                //check the flag of GPT
                if((!EFI_ERROR(Stauts)) && (gptHeader->Header.Signature == 0x5452415020494645))
                {
                    UINT32 CRCsum, GPTHeaderCRCsum = (gptHeader->Header.CRC32);
                    gptHeader->Header.CRC32 = 0;
                    gBS->CalculateCrc32(gptHeader, (gptHeader->Header.HeaderSize), &CRCsum);
                    if(GPTHeaderCRCsum == CRCsum)
                    {

                    }
                }

            // }
        
        }
            gBS->FreePool(DiskControllerHandles);   
    }

    return EFI_SUCCESS;
}


