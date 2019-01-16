/** @file
  This sample application bases on HelloWorld PCD setting 
  to print "UEFI Hello World!" to the UEFI Console.

  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials                          
  are licensed and made available under the terms and conditions of the BSD License         
  which accompanies this distribution.  The full text of the license may be found at        
  http://opensource.org/licenses/bsd-license.php                                            

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

**/

#include "UefiShellLevel1CommandsLib.h"

/**
  Function for 'helloworld' command.

  @param[in] ImageHandle  Handle to the Image (NULL if Internal).
  @param[in] SystemTable  Pointer to the System Table (NULL if Internal).
**/
SHELL_STATUS
EFIAPI
ShellCommandRunHelloWorld (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  EFI_STATUS          Status;
  SHELL_STATUS        ShellStatus;

  ShellStatus         = SHELL_SUCCESS;

  //
  // initialize the shell lib (we must be in non-auto-init...)
  //
  Status = ShellInitialize();
  ASSERT_EFI_ERROR(Status);

  Status = CommandInit();
  ASSERT_EFI_ERROR(Status);

  // clean the screen
  SystemTable->ConOut->ClearScreen(SystemTable->ConOut);

  UINT8               a=1;
  // Sample, use print
  Print(L"Hi this is my first application Hello World ! \n  test %d %d %d\n", a, a+1, a+2);

//--------------------------------------------------------------//
//                Simple Text Out Sample code                   //
//--------------------------------------------------------------//

  // Output String sample
  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"ConOut test 01\n");

  //---------------------------------------------------------------------------------
  //
  // EFI Console Colours
  //
  //#define EFI_BLACK                 0x00
  //#define EFI_BLUE                  0x01
  //#define EFI_GREEN                 0x02
  //#define EFI_CYAN                  (EFI_BLUE | EFI_GREEN)
  //#define EFI_RED                   0x04
  //#define EFI_MAGENTA               (EFI_BLUE | EFI_RED)
  //#define EFI_BROWN                 (EFI_GREEN | EFI_RED)
  //#define EFI_LIGHTGRAY             (EFI_BLUE | EFI_GREEN | EFI_RED)
  //#define EFI_BRIGHT                0x08
  //#define EFI_DARKGRAY              (EFI_BLACK | EFI_BRIGHT)
  //#define EFI_LIGHTBLUE             (EFI_BLUE | EFI_BRIGHT)
  //#define EFI_LIGHTGREEN            (EFI_GREEN | EFI_BRIGHT)
  //#define EFI_LIGHTCYAN             (EFI_CYAN | EFI_BRIGHT)
  //#define EFI_LIGHTRED              (EFI_RED | EFI_BRIGHT)
  //#define EFI_LIGHTMAGENTA          (EFI_MAGENTA | EFI_BRIGHT)
  //#define EFI_YELLOW                (EFI_BROWN | EFI_BRIGHT)
  //#define EFI_WHITE                 (EFI_BLUE | EFI_GREEN | EFI_RED | EFI_BRIGHT)

  //
  // Macro to accept color values in their raw form to create
  // a value that represents both a foreground and background
  // color in a single byte.
  // For Foreground, and EFI_* value is valid from EFI_BLACK(0x00) to
  // EFI_WHITE (0x0F).
  // For Background, only EFI_BLACK, EFI_BLUE, EFI_GREEN, EFI_CYAN,
  // EFI_RED, EFI_MAGENTA, EFI_BROWN, and EFI_LIGHTGRAY are acceptable
  //
  // Do not use EFI_BACKGROUND_xxx values with this macro.
  //
  //#define EFI_TEXT_ATTR(Foreground,Background) ((Foreground) | ((Background) << 4))

  //#define EFI_BACKGROUND_BLACK      0x00
  //#define EFI_BACKGROUND_BLUE       0x10
  //#define EFI_BACKGROUND_GREEN      0x20
  //#define EFI_BACKGROUND_CYAN       (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN)
  //#define EFI_BACKGROUND_RED        0x40
  //#define EFI_BACKGROUND_MAGENTA    (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_RED)
  //#define EFI_BACKGROUND_BROWN      (EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)
  //#define EFI_BACKGROUND_LIGHTGRAY  (EFI_BACKGROUND_BLUE | EFI_BACKGROUND_GREEN | EFI_BACKGROUND_RED)
  //---------------------------------------------------------------------------------
  // SetAttritube sample, set color
  SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_YELLOW | EFI_BACKGROUND_BLUE);
  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"setting the attritube to Yellow and background is blue\n");
  // set back the default color
  SystemTable->ConOut->SetAttribute(SystemTable->ConOut, EFI_LIGHTGRAY | EFI_BACKGROUND_BLACK);
  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Setting back to the default\n");
  // set the cursor position  Column, Row
  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 20, 5);
  SystemTable->ConOut->OutputString(SystemTable->ConOut, L"Setting the cursor Position\n");

//--------------------------------------------------------------//
//                Simple Text in Sample code                    //
//--------------------------------------------------------------//

//
// Required unicode control chars
//
//#define CHAR_BACKSPACE        0x0008
//#define CHAR_TAB              0x0009
//#define CHAR_LINEFEED         0x000A
//#define CHAR_CARRIAGE_RETURN  0x000D

//
// EFI Scan codes
//
//#define SCAN_NULL       0x0000
//#define SCAN_UP         0x0001
//#define SCAN_DOWN       0x0002
//#define SCAN_RIGHT      0x0003
//#define SCAN_LEFT       0x0004
//#define SCAN_HOME       0x0005
//#define SCAN_END        0x0006
//#define SCAN_INSERT     0x0007
//#define SCAN_DELETE     0x0008
//#define SCAN_PAGE_UP    0x0009
//#define SCAN_PAGE_DOWN  0x000A
//#define SCAN_F1         0x000B
//#define SCAN_F2         0x000C
//#define SCAN_F3         0x000D
//#define SCAN_F4         0x000E
//#define SCAN_F5         0x000F
//#define SCAN_F6         0x0010
//#define SCAN_F7         0x0011
//#define SCAN_F8         0x0012
//#define SCAN_F9         0x0013
//#define SCAN_F10        0x0014
//#define SCAN_ESC        0x0017

  EFI_INPUT_KEY           Key;
  UINTN                   Event=0;

  // clean key
  ZeroMem (&Key, sizeof (EFI_INPUT_KEY));

  SystemTable->ConOut->SetCursorPosition(SystemTable->ConOut, 0, 6);
  Print(L"Start the Scan code sample\n");
  while( Key.ScanCode != SCAN_ESC ){
    SystemTable->BootServices->WaitForEvent(1, &(SystemTable->ConIn->WaitForKey), &Event);
    SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key);
    Print(L"Read Key Scan code %x\n", Key.ScanCode);
    Print(L"Read Key Unicode char %x\n", Key.UnicodeChar);
  }

  return ShellStatus;
}
