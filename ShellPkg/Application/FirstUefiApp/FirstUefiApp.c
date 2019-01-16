//>>>>>>>>>>>>>>>>>>>>>NO.1<<<<<<<<<<<<<<<<<<<<<<<
// #include <Uefi.h>

// EFI_STATUS UEFIMain(IN EFI_HANDLE ImageHandle, IN EFI_SYSTEM_TABLE *SystemTable)
// {
//     //ClearScreen
//     SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

//     //Set the txt color to red and background to green.
//     SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_LIGHTRED | EFI_BACKGROUND_GREEN);
//     //Set the position to (20,5)
//     SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 20, 5);
//     //OutPut the message
//     SystemTable->ConOut->OutputString(SystemTable->ConOut, L"The First UEFI App from Michael!\n");
//     //set back to defualt color
//     SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_LIGHTGRAY | EFI_BACKGROUND_BLACK);
//     return EFI_SUCCESS;
// }


//>>>>>>>>>>>>>>>>>>>>>NO.2<<<<<<<<<<<<<<<<<<<<<<<
#include <Uefi.h>
#include <Library/UefiBootServicesTableLib.h>

INTN ShellAppMain(IN UINTN Argc, IN CHAR16 **Argv)
{
    
    //ClearScreen
    gST->ConOut->ClearScreen(gST->ConOut);

    //Set the txt color to EFI_LIGHTMAGENTA and background to green.
    gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTMAGENTA | EFI_BACKGROUND_BROWN);
    //Set the position to (20,5)
    gST->ConOut->SetCursorPosition(gST->ConOut, 20, 5);
    //OutPut the message
    gST->ConOut->OutputString(gST->ConOut, L"The second UEFI APP from Michael!\n");
        //set back to defualt color
    gST->ConOut->SetAttribute(gST->ConOut, EFI_LIGHTGRAY | EFI_BACKGROUND_BLACK);
    return 0;
}

