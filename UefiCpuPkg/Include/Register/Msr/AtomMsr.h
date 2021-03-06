/** @file
  MSR Definitions for the Intel(R) Atom(TM) Processor Family.

  Provides defines for Machine Specific Registers(MSR) indexes. Data structures
  are provided for MSRs that contain one or more bit fields.  If the MSR value
  returned is a single 32-bit or 64-bit value, then a data structure is not
  provided for that MSR.

  Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

  @par Specification Reference:
  Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 3,
  December 2015, Chapter 35 Model-Specific-Registers (MSR), Section 35-3.

**/

#ifndef __ATOM_MSR_H__
#define __ATOM_MSR_H__

#include <Register/ArchitecturalMsr.h>

/**
  Shared. Model Specific Platform ID (R).

  @param  ECX  MSR_ATOM_PLATFORM_ID (0x00000017)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_PLATFORM_ID_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_PLATFORM_ID_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_PLATFORM_ID_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_PLATFORM_ID);
  @endcode
**/
#define MSR_ATOM_PLATFORM_ID                     0x00000017

/**
  MSR information returned for MSR index #MSR_ATOM_PLATFORM_ID
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32  Reserved1:8;
    ///
    /// [Bits 12:8] Maximum Qualified Ratio (R)  The maximum allowed bus ratio.
    ///
    UINT32  MaximumQualifiedRatio:5;
    UINT32  Reserved2:19;
    UINT32  Reserved3:32;
  } Bits;
  ///
  /// All bit fields as a 32-bit value
  ///
  UINT32  Uint32;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_PLATFORM_ID_REGISTER;


/**
  Shared. Processor Hard Power-On Configuration (R/W) Enables and disables
  processor features; (R) indicates current processor configuration.

  @param  ECX  MSR_ATOM_EBL_CR_POWERON (0x0000002A)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_EBL_CR_POWERON_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_EBL_CR_POWERON_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_EBL_CR_POWERON_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_EBL_CR_POWERON);
  AsmWriteMsr64 (MSR_ATOM_EBL_CR_POWERON, Msr.Uint64);
  @endcode
**/
#define MSR_ATOM_EBL_CR_POWERON                  0x0000002A

/**
  MSR information returned for MSR index #MSR_ATOM_EBL_CR_POWERON
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32  Reserved1:1;
    ///
    /// [Bit 1] Data Error Checking Enable (R/W) 1 = Enabled; 0 = Disabled
    /// Always 0.
    ///
    UINT32  DataErrorCheckingEnable:1;
    ///
    /// [Bit 2] Response Error Checking Enable (R/W) 1 = Enabled; 0 = Disabled
    /// Always 0.
    ///
    UINT32  ResponseErrorCheckingEnable:1;
    ///
    /// [Bit 3] AERR# Drive Enable (R/W)  1 = Enabled; 0 = Disabled Always 0.
    ///
    UINT32  AERR_DriveEnable:1;
    ///
    /// [Bit 4] BERR# Enable for initiator bus requests (R/W) 1 = Enabled; 0 =
    /// Disabled Always 0.
    ///
    UINT32  BERR_Enable:1;
    UINT32  Reserved2:1;
    UINT32  Reserved3:1;
    ///
    /// [Bit 7] BINIT# Driver Enable (R/W) 1 = Enabled; 0 = Disabled Always 0.
    ///
    UINT32  BINIT_DriverEnable:1;
    UINT32  Reserved4:1;
    ///
    /// [Bit 9] Execute BIST (R/O) 1 = Enabled; 0 = Disabled.
    ///
    UINT32  ExecuteBIST:1;
    ///
    /// [Bit 10] AERR# Observation Enabled (R/O) 1 = Enabled; 0 = Disabled
    /// Always 0.
    ///
    UINT32  AERR_ObservationEnabled:1;
    UINT32  Reserved5:1;
    ///
    /// [Bit 12] BINIT# Observation Enabled (R/O) 1 = Enabled; 0 = Disabled
    /// Always 0.
    ///
    UINT32  BINIT_ObservationEnabled:1;
    UINT32  Reserved6:1;
    ///
    /// [Bit 14] 1 MByte Power on Reset Vector (R/O) 1 = 1 MByte; 0 = 4 GBytes.
    ///
    UINT32  ResetVector:1;
    UINT32  Reserved7:1;
    ///
    /// [Bits 17:16] APIC Cluster ID (R/O) Always 00B.
    ///
    UINT32  APICClusterID:2;
    UINT32  Reserved8:2;
    ///
    /// [Bits 21:20] Symmetric Arbitration ID (R/O) Always 00B.
    ///
    UINT32  SymmetricArbitrationID:2;
    ///
    /// [Bits 26:22] Integer Bus Frequency Ratio (R/O).
    ///
    UINT32  IntegerBusFrequencyRatio:5;
    UINT32  Reserved9:5;
    UINT32  Reserved10:32;
  } Bits;
  ///
  /// All bit fields as a 32-bit value
  ///
  UINT32  Uint32;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_EBL_CR_POWERON_REGISTER;


/**
  Unique. Last Branch Record 0 From IP (R/W) One of eight pairs of last branch
  record registers on the last branch record stack. This part of the stack
  contains pointers to the source instruction for one of the last eight
  branches, exceptions, or interrupts taken by the processor. See also: -
  Last Branch Record Stack TOS at 1C9H -  Section 17.12, "Last Branch,
  Interrupt, and Exception Recording (Pentium M Processors).".

  @param  ECX  MSR_ATOM_LASTBRANCH_n_FROM_IP
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_LASTBRANCH_0_FROM_IP);
  AsmWriteMsr64 (MSR_ATOM_LASTBRANCH_0_FROM_IP, Msr);
  @endcode
  @{
**/
#define MSR_ATOM_LASTBRANCH_0_FROM_IP            0x00000040
#define MSR_ATOM_LASTBRANCH_1_FROM_IP            0x00000041
#define MSR_ATOM_LASTBRANCH_2_FROM_IP            0x00000042
#define MSR_ATOM_LASTBRANCH_3_FROM_IP            0x00000043
#define MSR_ATOM_LASTBRANCH_4_FROM_IP            0x00000044
#define MSR_ATOM_LASTBRANCH_5_FROM_IP            0x00000045
#define MSR_ATOM_LASTBRANCH_6_FROM_IP            0x00000046
#define MSR_ATOM_LASTBRANCH_7_FROM_IP            0x00000047
/// @}


/**
  Unique. Last Branch Record 0 To IP (R/W) One of eight pairs of last branch
  record registers on the last branch record stack. This part of the stack
  contains pointers to the destination instruction for one of the last eight
  branches, exceptions, or interrupts taken by the processor.

  @param  ECX  MSR_ATOM_LASTBRANCH_n_TO_IP
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_LASTBRANCH_0_TO_IP);
  AsmWriteMsr64 (MSR_ATOM_LASTBRANCH_0_TO_IP, Msr);
  @endcode
  @{
**/
#define MSR_ATOM_LASTBRANCH_0_TO_IP              0x00000060
#define MSR_ATOM_LASTBRANCH_1_TO_IP              0x00000061
#define MSR_ATOM_LASTBRANCH_2_TO_IP              0x00000062
#define MSR_ATOM_LASTBRANCH_3_TO_IP              0x00000063
#define MSR_ATOM_LASTBRANCH_4_TO_IP              0x00000064
#define MSR_ATOM_LASTBRANCH_5_TO_IP              0x00000065
#define MSR_ATOM_LASTBRANCH_6_TO_IP              0x00000066
#define MSR_ATOM_LASTBRANCH_7_TO_IP              0x00000067
/// @}


/**
  Shared. Scalable Bus Speed(RO) This field indicates the intended scalable
  bus clock speed for processors based on Intel Atom microarchitecture:.

  @param  ECX  MSR_ATOM_FSB_FREQ (0x000000CD)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_FSB_FREQ_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_FSB_FREQ_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_FSB_FREQ_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_FSB_FREQ);
  @endcode
**/
#define MSR_ATOM_FSB_FREQ                        0x000000CD

/**
  MSR information returned for MSR index #MSR_ATOM_FSB_FREQ
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    ///
    /// [Bits 2:0] - Scalable Bus Speed
    ///
    /// Atom Processor Family
    /// ---------------------
    ///   111B: 083 MHz (FSB 333)
    ///   101B: 100 MHz (FSB 400)
    ///   001B: 133 MHz (FSB 533)
    ///   011B: 167 MHz (FSB 667)
    ///
    /// 133.33 MHz should be utilized if performing calculation with
    /// System Bus Speed when encoding is 001B.
    /// 166.67 MHz should be utilized if performing calculation with
    /// System Bus Speed when
    /// encoding is 011B.
    ///
    UINT32  ScalableBusSpeed:3;
    UINT32  Reserved1:29;
    UINT32  Reserved2:32;
  } Bits;
  ///
  /// All bit fields as a 32-bit value
  ///
  UINT32  Uint32;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_FSB_FREQ_REGISTER;


/**
  Shared.

  @param  ECX  MSR_ATOM_BBL_CR_CTL3 (0x0000011E)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_BBL_CR_CTL3_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_BBL_CR_CTL3_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_BBL_CR_CTL3_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_BBL_CR_CTL3);
  AsmWriteMsr64 (MSR_ATOM_BBL_CR_CTL3, Msr.Uint64);
  @endcode
**/
#define MSR_ATOM_BBL_CR_CTL3                     0x0000011E

/**
  MSR information returned for MSR index #MSR_ATOM_BBL_CR_CTL3
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    ///
    /// [Bit 0] L2 Hardware Enabled (RO) 1 = If the L2 is hardware-enabled 0 =
    /// Indicates if the L2 is hardware-disabled.
    ///
    UINT32  L2HardwareEnabled:1;
    UINT32  Reserved1:7;
    ///
    /// [Bit 8] L2 Enabled. (R/W)  1 = L2 cache has been initialized 0 =
    /// Disabled (default) Until this bit is set the processor will not
    /// respond to the WBINVD instruction or the assertion of the FLUSH# input.
    ///
    UINT32  L2Enabled:1;
    UINT32  Reserved2:14;
    ///
    /// [Bit 23] L2 Not Present (RO)  1. = L2 Present 2. = L2 Not Present.
    ///
    UINT32  L2NotPresent:1;
    UINT32  Reserved3:8;
    UINT32  Reserved4:32;
  } Bits;
  ///
  /// All bit fields as a 32-bit value
  ///
  UINT32  Uint32;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_BBL_CR_CTL3_REGISTER;


/**
  Shared.

  @param  ECX  MSR_ATOM_PERF_STATUS (0x00000198)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_PERF_STATUS_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_PERF_STATUS_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_PERF_STATUS_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_PERF_STATUS);
  AsmWriteMsr64 (MSR_ATOM_PERF_STATUS, Msr.Uint64);
  @endcode
**/
#define MSR_ATOM_PERF_STATUS                     0x00000198

/**
  MSR information returned for MSR index #MSR_ATOM_PERF_STATUS
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    ///
    /// [Bits 15:0] Current Performance State Value.
    ///
    UINT32  CurrentPerformanceStateValue:16;
    UINT32  Reserved1:16;
    UINT32  Reserved2:8;
    ///
    /// [Bits 44:40] Maximum Bus Ratio (R/O) Indicates maximum bus ratio
    /// configured for the processor.
    ///
    UINT32  MaximumBusRatio:5;
    UINT32  Reserved3:19;
  } Bits;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_PERF_STATUS_REGISTER;


/**
  Shared.

  @param  ECX  MSR_ATOM_THERM2_CTL (0x0000019D)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_THERM2_CTL_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_THERM2_CTL_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_THERM2_CTL_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_THERM2_CTL);
  AsmWriteMsr64 (MSR_ATOM_THERM2_CTL, Msr.Uint64);
  @endcode
**/
#define MSR_ATOM_THERM2_CTL                      0x0000019D

/**
  MSR information returned for MSR index #MSR_ATOM_THERM2_CTL
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    UINT32  Reserved1:16;
    ///
    /// [Bit 16] TM_SELECT (R/W)  Mode of automatic thermal monitor: 1. =
    /// Thermal Monitor 1 (thermally-initiated on-die modulation of the
    /// stop-clock duty cycle) 2. = Thermal Monitor 2 (thermally-initiated
    /// frequency transitions) If bit 3 of the IA32_MISC_ENABLE register is
    /// cleared, TM_SELECT has no effect. Neither TM1 nor TM2 are enabled.
    ///
    UINT32  TM_SELECT:1;
    UINT32  Reserved2:15;
    UINT32  Reserved3:32;
  } Bits;
  ///
  /// All bit fields as a 32-bit value
  ///
  UINT32  Uint32;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_THERM2_CTL_REGISTER;


/**
  Unique. Enable Misc. Processor Features (R/W)  Allows a variety of processor
  functions to be enabled and disabled.

  @param  ECX  MSR_ATOM_IA32_MISC_ENABLE (0x000001A0)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_IA32_MISC_ENABLE_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_IA32_MISC_ENABLE_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_IA32_MISC_ENABLE_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_IA32_MISC_ENABLE);
  AsmWriteMsr64 (MSR_ATOM_IA32_MISC_ENABLE, Msr.Uint64);
  @endcode
**/
#define MSR_ATOM_IA32_MISC_ENABLE                0x000001A0

/**
  MSR information returned for MSR index #MSR_ATOM_IA32_MISC_ENABLE
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    ///
    /// [Bit 0] Fast-Strings Enable See Table 35-2.
    ///
    UINT32  FastStrings:1;
    UINT32  Reserved1:2;
    ///
    /// [Bit 3] Unique. Automatic Thermal Control Circuit Enable (R/W) See
    /// Table 35-2.
    ///
    UINT32  AutomaticThermalControlCircuit:1;
    UINT32  Reserved2:3;
    ///
    /// [Bit 7] Shared. Performance Monitoring Available (R) See Table 35-2.
    ///
    UINT32  PerformanceMonitoring:1;
    UINT32  Reserved3:1;
    UINT32  Reserved4:1;
    ///
    /// [Bit 10] Shared. FERR# Multiplexing Enable (R/W) 1 = FERR# asserted by
    /// the processor to indicate a pending break event within the processor 0
    /// = Indicates compatible FERR# signaling behavior This bit must be set
    /// to 1 to support XAPIC interrupt model usage.
    ///
    UINT32  FERR:1;
    ///
    /// [Bit 11] Shared. Branch Trace Storage Unavailable (RO) See Table 35-2.
    ///
    UINT32  BTS:1;
    ///
    /// [Bit 12] Shared. Precise Event Based Sampling Unavailable (RO) See
    /// Table 35-2.
    ///
    UINT32  PEBS:1;
    ///
    /// [Bit 13] Shared. TM2 Enable (R/W) When this bit is set (1) and the
    /// thermal sensor indicates that the die temperature is at the
    /// pre-determined threshold, the Thermal Monitor 2 mechanism is engaged.
    /// TM2 will reduce the bus to core ratio and voltage according to the
    /// value last written to MSR_THERM2_CTL bits 15:0.
    ///   When this bit is clear (0, default), the processor does not change
    ///   the VID signals or the bus to core ratio when the processor enters a
    ///   thermally managed state. The BIOS must enable this feature if the
    ///   TM2 feature flag (CPUID.1:ECX[8]) is set; if the TM2 feature flag is
    ///   not set, this feature is not supported and BIOS must not alter the
    ///   contents of the TM2 bit location. The processor is operating out of
    ///   specification if both this bit and the TM1 bit are set to 0.
    ///
    UINT32  TM2:1;
    UINT32  Reserved5:2;
    ///
    /// [Bit 16] Shared. Enhanced Intel SpeedStep Technology Enable (R/W) See
    /// Table 35-2.
    ///
    UINT32  EIST:1;
    UINT32  Reserved6:1;
    ///
    /// [Bit 18] Shared. ENABLE MONITOR FSM (R/W) See Table 35-2.
    ///
    UINT32  MONITOR:1;
    UINT32  Reserved7:1;
    ///
    /// [Bit 20] Shared. Enhanced Intel SpeedStep Technology Select Lock
    /// (R/WO) When set, this bit causes the following bits to become
    /// read-only: -  Enhanced Intel SpeedStep Technology Select Lock (this
    /// bit), -  Enhanced Intel SpeedStep Technology Enable bit. The bit must
    /// be set before an Enhanced Intel SpeedStep Technology transition is
    /// requested. This bit is cleared on reset.
    ///
    UINT32  EISTLock:1;
    UINT32  Reserved8:1;
    ///
    /// [Bit 22] Unique. Limit CPUID Maxval (R/W) See Table 35-2.
    ///
    UINT32  LimitCpuidMaxval:1;
    ///
    /// [Bit 23] Shared. xTPR Message Disable (R/W) See Table 35-2.
    ///
    UINT32  xTPR_Message_Disable:1;
    UINT32  Reserved9:8;
    UINT32  Reserved10:2;
    ///
    /// [Bit 34] Unique. XD Bit Disable (R/W) See Table 35-2.
    ///
    UINT32  XD:1;
    UINT32  Reserved11:29;
  } Bits;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_IA32_MISC_ENABLE_REGISTER;


/**
  Unique. Last Branch Record Stack TOS (R/W)  Contains an index (bits 0-2)
  that points to the MSR containing the most recent branch record. See
  MSR_LASTBRANCH_0_FROM_IP (at 40H).

  @param  ECX  MSR_ATOM_LASTBRANCH_TOS (0x000001C9)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_LASTBRANCH_TOS);
  AsmWriteMsr64 (MSR_ATOM_LASTBRANCH_TOS, Msr);
  @endcode
**/
#define MSR_ATOM_LASTBRANCH_TOS                  0x000001C9


/**
  Unique. Last Exception Record From Linear IP (R)  Contains a pointer to the
  last branch instruction that the processor executed prior to the last
  exception that was generated or the last interrupt that was handled.

  @param  ECX  MSR_ATOM_LER_FROM_LIP (0x000001DD)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_LER_FROM_LIP);
  @endcode
**/
#define MSR_ATOM_LER_FROM_LIP                    0x000001DD


/**
  Unique. Last Exception Record To Linear IP (R)  This area contains a pointer
  to the target of the last branch instruction that the processor executed
  prior to the last exception that was generated or the last interrupt that
  was handled.

  @param  ECX  MSR_ATOM_LER_TO_LIP (0x000001DE)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_LER_TO_LIP);
  @endcode
**/
#define MSR_ATOM_LER_TO_LIP                      0x000001DE


/**
  Unique. See Table 35-2. See Section 18.4.2, "Global Counter Control
  Facilities.".

  @param  ECX  MSR_ATOM_IA32_PERF_GLOBAL_STAUS (0x0000038E)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_IA32_PERF_GLOBAL_STAUS);
  AsmWriteMsr64 (MSR_ATOM_IA32_PERF_GLOBAL_STAUS, Msr);
  @endcode
**/
#define MSR_ATOM_IA32_PERF_GLOBAL_STAUS          0x0000038E


/**
  Unique. See Table 35-2. See Section 18.4.4, "Precise Event Based Sampling
  (PEBS).".

  @param  ECX  MSR_ATOM_PEBS_ENABLE (0x000003F1)
  @param  EAX  Lower 32-bits of MSR value.
               Described by the type MSR_ATOM_PEBS_ENABLE_REGISTER.
  @param  EDX  Upper 32-bits of MSR value.
               Described by the type MSR_ATOM_PEBS_ENABLE_REGISTER.

  <b>Example usage</b>
  @code
  MSR_ATOM_PEBS_ENABLE_REGISTER  Msr;

  Msr.Uint64 = AsmReadMsr64 (MSR_ATOM_PEBS_ENABLE);
  AsmWriteMsr64 (MSR_ATOM_PEBS_ENABLE, Msr.Uint64);
  @endcode
**/
#define MSR_ATOM_PEBS_ENABLE                     0x000003F1

/**
  MSR information returned for MSR index #MSR_ATOM_PEBS_ENABLE
**/
typedef union {
  ///
  /// Individual bit fields
  ///
  struct {
    ///
    /// [Bit 0] Enable PEBS on IA32_PMC0. (R/W).
    ///
    UINT32  Enable:1;
    UINT32  Reserved1:31;
    UINT32  Reserved2:32;
  } Bits;
  ///
  /// All bit fields as a 32-bit value
  ///
  UINT32  Uint32;
  ///
  /// All bit fields as a 64-bit value
  ///
  UINT64  Uint64;
} MSR_ATOM_PEBS_ENABLE_REGISTER;


/**
  Shared. See Section 15.3.2.1, "IA32_MCi_CTL MSRs.".

  @param  ECX  MSR_ATOM_MC3_CTL (0x0000040C)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_MC3_CTL);
  AsmWriteMsr64 (MSR_ATOM_MC3_CTL, Msr);
  @endcode
**/
#define MSR_ATOM_MC3_CTL                         0x0000040C


/**
  Shared. See Section 15.3.2.2, "IA32_MCi_STATUS MSRS.".

  @param  ECX  MSR_ATOM_MC3_STATUS (0x0000040D)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_MC3_STATUS);
  AsmWriteMsr64 (MSR_ATOM_MC3_STATUS, Msr);
  @endcode
**/
#define MSR_ATOM_MC3_STATUS                      0x0000040D


/**
  Shared. See Section 15.3.2.3, "IA32_MCi_ADDR MSRs." The MSR_MC3_ADDR
  register is either not implemented or contains no address if the ADDRV flag
  in the MSR_MC3_STATUS register is clear. When not implemented in the
  processor, all reads and writes to this MSR will cause a general-protection
  exception.

  @param  ECX  MSR_ATOM_MC3_ADDR (0x0000040E)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_MC3_ADDR);
  AsmWriteMsr64 (MSR_ATOM_MC3_ADDR, Msr);
  @endcode
**/
#define MSR_ATOM_MC3_ADDR                        0x0000040E


/**
  Shared. See Section 15.3.2.1, "IA32_MCi_CTL MSRs.".

  @param  ECX  MSR_ATOM_MC4_CTL (0x00000410)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_MC4_CTL);
  AsmWriteMsr64 (MSR_ATOM_MC4_CTL, Msr);
  @endcode
**/
#define MSR_ATOM_MC4_CTL                         0x00000410


/**
  Shared. See Section 15.3.2.2, "IA32_MCi_STATUS MSRS.".

  @param  ECX  MSR_ATOM_MC4_STATUS (0x00000411)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_MC4_STATUS);
  AsmWriteMsr64 (MSR_ATOM_MC4_STATUS, Msr);
  @endcode
**/
#define MSR_ATOM_MC4_STATUS                      0x00000411


/**
  Shared. See Section 15.3.2.3, "IA32_MCi_ADDR MSRs." The MSR_MC4_ADDR
  register is either not implemented or contains no address if the ADDRV flag
  in the MSR_MC4_STATUS register is clear. When not implemented in the
  processor, all reads and writes to this MSR will cause a general-protection
  exception.

  @param  ECX  MSR_ATOM_MC4_ADDR (0x00000412)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_MC4_ADDR);
  AsmWriteMsr64 (MSR_ATOM_MC4_ADDR, Msr);
  @endcode
**/
#define MSR_ATOM_MC4_ADDR                        0x00000412


/**
  Package. Package C2 Residency Note: C-state values are processor specific
  C-state code names, unrelated to MWAIT extension C-state parameters or ACPI
  C-States. Package. Package C2 Residency Counter. (R/O) Time that this
  package is in processor-specific C2 states since last reset. Counts at 1 Mhz
  frequency.

  @param  ECX  MSR_ATOM_PKG_C2_RESIDENCY (0x000003F8)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_PKG_C2_RESIDENCY);
  AsmWriteMsr64 (MSR_ATOM_PKG_C2_RESIDENCY, Msr);
  @endcode
**/
#define MSR_ATOM_PKG_C2_RESIDENCY                0x000003F8


/**
  Package. Package C4 Residency Note: C-state values are processor specific
  C-state code names, unrelated to MWAIT extension C-state parameters or ACPI
  C-States. Package. Package C4 Residency Counter. (R/O) Time that this
  package is in processor-specific C4 states since last reset. Counts at 1 Mhz
  frequency.

  @param  ECX  MSR_ATOM_PKG_C4_RESIDENCY (0x000003F9)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_PKG_C4_RESIDENCY);
  AsmWriteMsr64 (MSR_ATOM_PKG_C4_RESIDENCY, Msr);
  @endcode
**/
#define MSR_ATOM_PKG_C4_RESIDENCY                0x000003F9


/**
  Package. Package C6 Residency Note: C-state values are processor specific
  C-state code names, unrelated to MWAIT extension C-state parameters or ACPI
  C-States. Package. Package C6 Residency Counter. (R/O) Time that this
  package is in processor-specific C6 states since last reset. Counts at 1 Mhz
  frequency.

  @param  ECX  MSR_ATOM_PKG_C6_RESIDENCY (0x000003FA)
  @param  EAX  Lower 32-bits of MSR value.
  @param  EDX  Upper 32-bits of MSR value.

  <b>Example usage</b>
  @code
  UINT64  Msr;

  Msr = AsmReadMsr64 (MSR_ATOM_PKG_C6_RESIDENCY);
  AsmWriteMsr64 (MSR_ATOM_PKG_C6_RESIDENCY, Msr);
  @endcode
**/
#define MSR_ATOM_PKG_C6_RESIDENCY                0x000003FA

#endif
