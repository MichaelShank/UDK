#------------------------------------------------------------------------------ ;
# Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>
# This program and the accompanying materials
# are licensed and made available under the terms and conditions of the BSD License
# which accompanies this distribution.  The full text of the license may be found at
# http://opensource.org/licenses/bsd-license.php.
#
# THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
# WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
# Module Name:
#
#   RdRand.S
#
# Abstract:
#
#   Generates random number through CPU RdRand instruction under 64-bit platform.
#
# Notes:
#
#------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//  Generates a 16 bit random number through RDRAND instruction.
//  Return TRUE if Rand generated successfully, or FALSE if not.
//
//  BOOLEAN EFIAPI AsmRdRand16 (UINT16 *Rand);
//------------------------------------------------------------------------------
ASM_GLOBAL ASM_PFX(AsmRdRand16)
ASM_PFX(AsmRdRand16):
    .byte  0x0f, 0xc7, 0xf0        // rdrand r16: "0f c7 /6  ModRM:r/m(w)"
    jc     rn16_ok                 // jmp if CF=1
    xor    %rax, %rax              // reg=0 if CF=0
    ret                            // return with failure status
rn16_ok:
    mov    %ax, (%rcx)
    mov    $0x1, %rax
    ret

//------------------------------------------------------------------------------
//  Generates a 32 bit random number through RDRAND instruction.
//  Return TRUE if Rand generated successfully, or FALSE if not.
//
//  BOOLEAN EFIAPI AsmRdRand32 (UINT32 *Rand);
//------------------------------------------------------------------------------
ASM_GLOBAL ASM_PFX(AsmRdRand32)
ASM_PFX(AsmRdRand32):
    .byte  0x0f, 0xc7, 0xf0        // rdrand r32: "0f c7 /6  ModRM:r/m(w)"
    jc     rn32_ok                 // jmp if CF=1
    xor    %rax, %rax              // reg=0 if CF=0
    ret                            // return with failure status
rn32_ok:
    mov    %eax, (%rcx)
    mov    $0x1, %rax
    ret

//------------------------------------------------------------------------------
//  Generates a 64 bit random number through RDRAND instruction.
//  Return TRUE if Rand generated successfully, or FALSE if not.
//
//  BOOLEAN EFIAPI AsmRdRand64 (UINT64 *Rand);
//------------------------------------------------------------------------------
ASM_GLOBAL ASM_PFX(AsmRdRand64)
ASM_PFX(AsmRdRand64):
    .byte  0x48, 0x0f, 0xc7, 0xf0  // rdrand r64: "REX.W + 0f c7 /6 ModRM:r/m(w)"
    jc     rn64_ok                 // jmp if CF=1
    xor    %rax, %rax              // reg=0 if CF=0
    ret                            // return with failure status
rn64_ok:
    mov    %rax, (%rcx)
    mov    $0x1, %rax
    ret
