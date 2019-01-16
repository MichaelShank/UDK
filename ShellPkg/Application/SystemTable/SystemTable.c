#include <Uefi.h>
//#include <Library/UefiBootServicesTableLib.h>

#define SCAN_ESC        0x0017

EFI_STATUS UefiMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
{
    EFI_STATUS Status;
    UINTN Index;
    EFI_INPUT_KEY Key;
    CHAR16 Strbuffer[3] = {0};
//    UINTN times;
    UINTN Raw = 1;
    UINTN Column = 0;

    //ClearScreen
    SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

    for(Raw = 1;Raw>0;Raw++)
    {

        SystemTable->BootServices->WaitForEvent(1, &SystemTable->ConIn->WaitForKey, &Index);
        Status = SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key);
        Strbuffer[0] = Key.UnicodeChar;
        Strbuffer[1] = '\n';

        //if press ESC, then exit the program.
        if (Key.ScanCode == SCAN_ESC)
            return EFI_SUCCESS;
        
        // if('a'<Key.UnicodeChar<'z')//if input Number, then the number show green
        // {
            SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_GREEN | EFI_BACKGROUND_BLACK);
            SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, Raw, Column);
            SystemTable->ConOut->OutputString(SystemTable->ConOut, Strbuffer);
        // }
        // else
        // {
            // SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_BLUE | EFI_BACKGROUND_BLACK);
            // SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, Raw, Column);
            // SystemTable->ConOut->OutputString(SystemTable->ConOut, Strbuffer);
        // }

        //this is 64 char every raw.
        if (!(Raw % 64))
        {
            Raw = 1;
            Column++;
        }
    }
    return EFI_SUCCESS;
}