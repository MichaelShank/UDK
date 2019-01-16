@REM
@REM This batch file only for building my own pkg and application.
@REM

@REM
@REM set the parameters
@REM

@REM TARGET= RELEASE or DEBUG
SET PKG=ShellPkg
SET MYAPPPKG_APP=%PKG%\Application
SET PLATFORMFILE=%PKG%\%PKG%.dsc
@REM TARGET= RELEASE or DEBUG
SET TARGET=RELEASE
@REM TARGETARCH= IA32 or X64
SET TARGETARCH=X64
@REM TOOLCHAIN
SET TOOLCHAIN=VS2015x86
@REM max CPU compile thread
SET THREADNUMBER=1
@REM Setting the build path
SET BUILD_PATH=Build\Shell\%TARGET%_%TOOLCHAIN%\%TARGETARCH%
@REM Setting the NT32X64 path
SET NE32X64_PATH=Build\NT32X64\%TARGET%_%TOOLCHAIN%\%TARGETARCH%

@REM ===== Build condition =====
IF "%1"=="" GOTO build
IF "%1"=="c" GOTO clean
IF "%1"=="C" GOTO clean

@REM ================================================
@REM Compile MyAppPkg
@REM
@REM -p PLATFORMFILE , ACTIVE_PLATFORM
@REM -b BUILDTARGET, TARGET
@REM -a TARGETARCH, TARGET_ARCH
@REM -t TOOLCHAIN, TOOL_CHAIN_TAG
@REM -n THREADNUMBER, MAX_CONCURRENT_THREAD_NUMBER
@REM ================================================

:build
@REM Clean the Temp file
rmdir Build /s /q
@REM if there is shell package in build folder then delete it.
@rem build -p %PLATFORMFILE% -b %TARGET% -a %TARGETARCH% -t %TOOLCHAIN% -n %THREADNUMBER%
build -a %TARGETARCH% -p %PLATFORMFILE%
GOTO copy

@REM Clean the Temp file
:clean
rmdir Build /s /q
GOTO end

:copy 
copy %BUILD_PATH%\*.efi Build
GOTO end
:end

