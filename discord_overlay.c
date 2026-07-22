typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned long long    qword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef unsigned short    word;
typedef struct CLIENT_ID CLIENT_ID, *PCLIENT_ID;

struct CLIENT_ID {
    void *UniqueProcess;
    void *UniqueThread;
};

typedef struct GuardCfgTableEntry GuardCfgTableEntry, *PGuardCfgTableEntry;

struct GuardCfgTableEntry {
    ImageBaseOffset32 Offset;
};

typedef struct _M128A _M128A, *P_M128A;

typedef ulonglong ULONGLONG;

typedef longlong LONGLONG;

struct _M128A {
    ULONGLONG Low;
    LONGLONG High;
};

typedef struct _XSAVE_FORMAT _XSAVE_FORMAT, *P_XSAVE_FORMAT;

typedef struct _XSAVE_FORMAT XSAVE_FORMAT;

typedef ushort WORD;

typedef uchar BYTE;

typedef ulong DWORD;

typedef struct _M128A M128A;

struct _XSAVE_FORMAT {
    WORD ControlWord;
    WORD StatusWord;
    BYTE TagWord;
    BYTE Reserved1;
    WORD ErrorOpcode;
    DWORD ErrorOffset;
    WORD ErrorSelector;
    WORD Reserved2;
    DWORD DataOffset;
    WORD DataSelector;
    WORD Reserved3;
    DWORD MxCsr;
    DWORD MxCsr_Mask;
    M128A FloatRegisters[8];
    M128A XmmRegisters[16];
    BYTE Reserved4[96];
};

typedef union _union_54 _union_54, *P_union_54;

typedef XSAVE_FORMAT XMM_SAVE_AREA32;

typedef struct _struct_55 _struct_55, *P_struct_55;

struct _struct_55 {
    M128A Header[2];
    M128A Legacy[8];
    M128A Xmm0;
    M128A Xmm1;
    M128A Xmm2;
    M128A Xmm3;
    M128A Xmm4;
    M128A Xmm5;
    M128A Xmm6;
    M128A Xmm7;
    M128A Xmm8;
    M128A Xmm9;
    M128A Xmm10;
    M128A Xmm11;
    M128A Xmm12;
    M128A Xmm13;
    M128A Xmm14;
    M128A Xmm15;
};

union _union_54 {
    XMM_SAVE_AREA32 FltSave;
    struct _struct_55 s;
};

typedef void *PVOID;

typedef struct IMAGE_DOS_HEADER IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

struct IMAGE_DOS_HEADER {
    char e_magic[2]; // Magic number
    word e_cblp; // Bytes of last page
    word e_cp; // Pages in file
    word e_crlc; // Relocations
    word e_cparhdr; // Size of header in paragraphs
    word e_minalloc; // Minimum extra paragraphs needed
    word e_maxalloc; // Maximum extra paragraphs needed
    word e_ss; // Initial (relative) SS value
    word e_sp; // Initial SP value
    word e_csum; // Checksum
    word e_ip; // Initial IP value
    word e_cs; // Initial (relative) CS value
    word e_lfarlc; // File address of relocation table
    word e_ovno; // Overlay number
    word e_res[4][4]; // Reserved words
    word e_oemid; // OEM identifier (for e_oeminfo)
    word e_oeminfo; // OEM information; e_oemid specific
    word e_res2[10][10]; // Reserved words
    dword e_lfanew; // File address of new exe header
    byte e_program[64]; // Actual DOS program
};

typedef struct _DISPATCHER_CONTEXT _DISPATCHER_CONTEXT, *P_DISPATCHER_CONTEXT;

struct _DISPATCHER_CONTEXT {
};

typedef struct _CONTEXT _CONTEXT, *P_CONTEXT;

typedef ulonglong DWORD64;

struct _CONTEXT {
    DWORD64 P1Home;
    DWORD64 P2Home;
    DWORD64 P3Home;
    DWORD64 P4Home;
    DWORD64 P5Home;
    DWORD64 P6Home;
    DWORD ContextFlags;
    DWORD MxCsr;
    WORD SegCs;
    WORD SegDs;
    WORD SegEs;
    WORD SegFs;
    WORD SegGs;
    WORD SegSs;
    DWORD EFlags;
    DWORD64 Dr0;
    DWORD64 Dr1;
    DWORD64 Dr2;
    DWORD64 Dr3;
    DWORD64 Dr6;
    DWORD64 Dr7;
    DWORD64 Rax;
    DWORD64 Rcx;
    DWORD64 Rdx;
    DWORD64 Rbx;
    DWORD64 Rsp;
    DWORD64 Rbp;
    DWORD64 Rsi;
    DWORD64 Rdi;
    DWORD64 R8;
    DWORD64 R9;
    DWORD64 R10;
    DWORD64 R11;
    DWORD64 R12;
    DWORD64 R13;
    DWORD64 R14;
    DWORD64 R15;
    DWORD64 Rip;
    union _union_54 u;
    M128A VectorRegister[26];
    DWORD64 VectorControl;
    DWORD64 DebugControl;
    DWORD64 LastBranchToRip;
    DWORD64 LastBranchFromRip;
    DWORD64 LastExceptionToRip;
    DWORD64 LastExceptionFromRip;
};

typedef enum _EXCEPTION_DISPOSITION {
    ExceptionContinueExecution=0,
    ExceptionContinueSearch=1,
    ExceptionNestedException=2,
    ExceptionCollidedUnwind=3
} _EXCEPTION_DISPOSITION;

typedef struct _EXCEPTION_RECORD _EXCEPTION_RECORD, *P_EXCEPTION_RECORD;

typedef ulonglong ULONG_PTR;

struct _EXCEPTION_RECORD {
    DWORD ExceptionCode;
    DWORD ExceptionFlags;
    struct _EXCEPTION_RECORD *ExceptionRecord;
    PVOID ExceptionAddress;
    DWORD NumberParameters;
    ULONG_PTR ExceptionInformation[15];
};

typedef enum _EXCEPTION_DISPOSITION EXCEPTION_DISPOSITION;

typedef struct DotNetPdbInfo DotNetPdbInfo, *PDotNetPdbInfo;

struct DotNetPdbInfo {
    char signature[4];
    GUID guid;
    dword age;
    char pdbpath[61];
};

typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY _IMAGE_RUNTIME_FUNCTION_ENTRY, *P_IMAGE_RUNTIME_FUNCTION_ENTRY;

struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
    ImageBaseOffset32 BeginAddress;
    dword EndAddress; // Apply ImageBaseOffset32 to see reference
    ImageBaseOffset32 UnwindInfoAddressOrData;
};

typedef struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY IMAGE_LOAD_CONFIG_CODE_INTEGRITY, *PIMAGE_LOAD_CONFIG_CODE_INTEGRITY;

struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY {
    word Flags;
    word Catalog;
    dword CatalogOffset;
    dword Reserved;
};

typedef struct IMAGE_DEBUG_DIRECTORY IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};

typedef struct IMAGE_FILE_HEADER IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

struct IMAGE_FILE_HEADER {
    word Machine; // 34404
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};

typedef struct IMAGE_LOAD_CONFIG_DIRECTORY64 IMAGE_LOAD_CONFIG_DIRECTORY64, *PIMAGE_LOAD_CONFIG_DIRECTORY64;

typedef enum IMAGE_GUARD_FLAGS {
    IMAGE_GUARD_CF_INSTRUMENTED=256,
    IMAGE_GUARD_CFW_INSTRUMENTED=512,
    IMAGE_GUARD_CF_FUNCTION_TABLE_PRESENT=1024,
    IMAGE_GUARD_SECURITY_COOKIE_UNUSED=2048,
    IMAGE_GUARD_PROTECT_DELAYLOAD_IAT=4096,
    IMAGE_GUARD_DELAYLOAD_IAT_IN_ITS_OWN_SECTION=8192,
    IMAGE_GUARD_CF_EXPORT_SUPPRESSION_INFO_PRESENT=16384,
    IMAGE_GUARD_CF_ENABLE_EXPORT_SUPPRESSION=32768,
    IMAGE_GUARD_CF_LONGJUMP_TABLE_PRESENT=65536,
    IMAGE_GUARD_RF_INSTRUMENTED=131072,
    IMAGE_GUARD_RF_ENABLE=262144,
    IMAGE_GUARD_RF_STRICT=524288,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_1=268435456,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_2=536870912,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_4=1073741824,
    IMAGE_GUARD_CF_FUNCTION_TABLE_SIZE_MASK_8=2147483648
} IMAGE_GUARD_FLAGS;

struct IMAGE_LOAD_CONFIG_DIRECTORY64 {
    dword Size;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword GlobalFlagsClear;
    dword GlobalFlagsSet;
    dword CriticalSectionDefaultTimeout;
    qword DeCommitFreeBlockThreshold;
    qword DeCommitTotalFreeThreshold;
    pointer64 LockPrefixTable;
    qword MaximumAllocationSize;
    qword VirtualMemoryThreshold;
    qword ProcessAffinityMask;
    dword ProcessHeapFlags;
    word CsdVersion;
    word DependentLoadFlags;
    pointer64 EditList;
    pointer64 SecurityCookie;
    pointer64 SEHandlerTable;
    qword SEHandlerCount;
    pointer64 GuardCFCCheckFunctionPointer;
    pointer64 GuardCFDispatchFunctionPointer;
    pointer64 GuardCFFunctionTable;
    qword GuardCFFunctionCount;
    enum IMAGE_GUARD_FLAGS GuardFlags;
    struct IMAGE_LOAD_CONFIG_CODE_INTEGRITY CodeIntegrity;
    pointer64 GuardAddressTakenIatEntryTable;
    qword GuardAddressTakenIatEntryCount;
    pointer64 GuardLongJumpTargetTable;
    qword GuardLongJumpTargetCount;
    pointer64 DynamicValueRelocTable;
    pointer64 CHPEMetadataPointer;
    pointer64 GuardRFFailureRoutine;
    pointer64 GuardRFFailureRoutineFunctionPointer;
    dword DynamicValueRelocTableOffset;
    word DynamicValueRelocTableSection;
    word Reserved1;
    pointer64 GuardRFVerifyStackPointerFunctionPointer;
    dword HotPatchTableOffset;
    dword Reserved2;
    qword Reserved3;
};

typedef struct IMAGE_OPTIONAL_HEADER64 IMAGE_OPTIONAL_HEADER64, *PIMAGE_OPTIONAL_HEADER64;

typedef struct IMAGE_DATA_DIRECTORY IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};

struct IMAGE_OPTIONAL_HEADER64 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    pointer64 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    qword SizeOfStackReserve;
    qword SizeOfStackCommit;
    qword SizeOfHeapReserve;
    qword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    struct IMAGE_DATA_DIRECTORY DataDirectory[16];
};

typedef struct IMAGE_SECTION_HEADER IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

typedef union Misc Misc, *PMisc;

typedef enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD=8,
    IMAGE_SCN_RESERVED_0001=16,
    IMAGE_SCN_CNT_CODE=32,
    IMAGE_SCN_CNT_INITIALIZED_DATA=64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA=128,
    IMAGE_SCN_LNK_OTHER=256,
    IMAGE_SCN_LNK_INFO=512,
    IMAGE_SCN_RESERVED_0040=1024,
    IMAGE_SCN_LNK_REMOVE=2048,
    IMAGE_SCN_LNK_COMDAT=4096,
    IMAGE_SCN_GPREL=32768,
    IMAGE_SCN_MEM_16BIT=131072,
    IMAGE_SCN_MEM_PURGEABLE=131072,
    IMAGE_SCN_MEM_LOCKED=262144,
    IMAGE_SCN_MEM_PRELOAD=524288,
    IMAGE_SCN_ALIGN_1BYTES=1048576,
    IMAGE_SCN_ALIGN_2BYTES=2097152,
    IMAGE_SCN_ALIGN_4BYTES=3145728,
    IMAGE_SCN_ALIGN_8BYTES=4194304,
    IMAGE_SCN_ALIGN_16BYTES=5242880,
    IMAGE_SCN_ALIGN_32BYTES=6291456,
    IMAGE_SCN_ALIGN_64BYTES=7340032,
    IMAGE_SCN_ALIGN_128BYTES=8388608,
    IMAGE_SCN_ALIGN_256BYTES=9437184,
    IMAGE_SCN_ALIGN_512BYTES=10485760,
    IMAGE_SCN_ALIGN_1024BYTES=11534336,
    IMAGE_SCN_ALIGN_2048BYTES=12582912,
    IMAGE_SCN_ALIGN_4096BYTES=13631488,
    IMAGE_SCN_ALIGN_8192BYTES=14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL=16777216,
    IMAGE_SCN_MEM_DISCARDABLE=33554432,
    IMAGE_SCN_MEM_NOT_CACHED=67108864,
    IMAGE_SCN_MEM_NOT_PAGED=134217728,
    IMAGE_SCN_MEM_SHARED=268435456,
    IMAGE_SCN_MEM_EXECUTE=536870912,
    IMAGE_SCN_MEM_READ=1073741824,
    IMAGE_SCN_MEM_WRITE=2147483648
} SectionFlags;

union Misc {
    dword PhysicalAddress;
    dword VirtualSize;
};

struct IMAGE_SECTION_HEADER {
    char Name[8];
    union Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    enum SectionFlags Characteristics;
};

typedef struct IMAGE_NT_HEADERS64 IMAGE_NT_HEADERS64, *PIMAGE_NT_HEADERS64;

struct IMAGE_NT_HEADERS64 {
    char Signature[4];
    struct IMAGE_FILE_HEADER FileHeader;
    struct IMAGE_OPTIONAL_HEADER64 OptionalHeader;
};

typedef struct IMAGE_BASE_RELOCATION IMAGE_BASE_RELOCATION, *PIMAGE_BASE_RELOCATION;

struct IMAGE_BASE_RELOCATION {
    dword VirtualAddress;
    dword SizeOfBlock;
};

typedef ulonglong uintptr_t;



undefined DAT_1400070d0;
undefined DAT_1400080e0;
undefined DAT_1400090f0;
undefined DAT_1400060c8;
undefined DAT_1400070d8;
undefined DAT_1400080e8;
undefined DAT_1400090f8;
void *SubSystemTib;
ulonglong DAT_140005000;
undefined8 DAT_1400050b0;
longlong DAT_1400091c0;
longlong DAT_1400091d0;
longlong DAT_140009108;
undefined DAT_140005080;
longlong DAT_140009150;
longlong DAT_140009148;
undefined *PTR_IoDriverObjectType_140004020;
longlong DAT_1400060c0;
longlong DAT_140009188;
char *DAT_140009190;
undefined DAT_1400050b8;
undefined FUN_140002450;
longlong DAT_1400091a8;
ulonglong DAT_140009110;
undefined DAT_140005090;
undefined DAT_1400050a0;
ulonglong DAT_140009130;
undefined FUN_1400010e0;
ulonglong DAT_140009138;
undefined FUN_140002270;
undefined FUN_140003790;
undefined FUN_1400037c0;
ulonglong DAT_140009128;
ulonglong DAT_140009120;
ulonglong DAT_140009118;
ulonglong DAT_140009158;
ulonglong DAT_140009180;
ulonglong DAT_1400091c8;
ulonglong DAT_140009170;
ulonglong DAT_140009168;
ulonglong DAT_140009140;
longlong DAT_1400091b0;
char *DAT_1400091b8;
undefined8 *DAT_1400091a0;
ulonglong DAT_140009160;
ulonglong DAT_140009198;
ulonglong DAT_140009178;
undefined1 *DAT_140009170;
byte DAT_140005040;
uintptr_t DAT_140005000;

// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void FUN_140001000(void)

{
  FUN_140002a90(&DAT_1400060c8);
  _DAT_1400070d0 = 0;
  FUN_140002a90(&DAT_1400070d8);
  _DAT_1400080e0 = 0;
  FUN_140002a90(&DAT_1400080e8);
  _DAT_1400090f0 = 0;
  FUN_140002a90(&DAT_1400090f8);
  return;
}



ulonglong FUN_140001060(void)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  
  uVar2 = *(ulonglong *)(*(longlong *)((longlong)SubSystemTib + 0x38) + 4) & 0xfffffffffffff000;
  do {
    lVar3 = 0;
    do {
      if ((((*(char *)(uVar2 + lVar3) == 'H') && (*(char *)(uVar2 + 1 + lVar3) == -0x73)) &&
          (*(char *)(uVar2 + 2 + lVar3) == '\x1d')) && (*(char *)(uVar2 + 6 + lVar3) == -1)) {
        iVar1 = *(int *)(uVar2 + 3 + lVar3);
        if (((int)lVar3 + iVar1 + 7U & 0xfff) == 0) {
          return (ulonglong)((int)lVar3 + iVar1 + 7) | uVar2 & 0xffffffff00000000;
        }
      }
      lVar3 = lVar3 + 1;
    } while (lVar3 != 0xff9);
    uVar2 = uVar2 - 0x1000;
  } while( true );
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

int FUN_1400010e0(longlong param_1,longlong param_2)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined8 *puVar4;
  ulonglong uVar5;
  undefined1 auVar6 [16];
  undefined1 auVar7 [16];
  int iVar8;
  int iVar9;
  longlong lVar10;
  undefined8 uVar11;
  longlong lVar12;
  undefined8 uVar13;
  ulonglong uVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  undefined4 uVar36;
  undefined4 uVar37;
  undefined4 uVar38;
  undefined4 uVar39;
  undefined4 uVar40;
  undefined4 uVar41;
  undefined4 uVar42;
  undefined1 auStackY_1e8 [32];
  ulonglong local_1b8;
  longlong local_1b0;
  undefined1 local_1a8 [16];
  undefined1 local_198 [16];
  undefined1 local_188 [16];
  undefined1 local_178 [16];
  undefined4 local_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 local_158;
  undefined4 uStack_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 local_138;
  undefined4 uStack_134;
  undefined1 uStack_130;
  undefined7 uStack_12f;
  undefined8 local_128;
  int iStack_120;
  undefined4 uStack_11c;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  byte local_e8 [16];
  uint local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined2 local_cc;
  undefined1 local_ca;
  longlong local_c9;
  undefined4 local_c1;
  undefined2 local_bd;
  undefined1 local_bb;
  ulonglong local_b8 [3];
  undefined4 local_a0;
  undefined2 local_9c;
  ulonglong local_98;
  
  local_98 = DAT_140005000 ^ (ulonglong)auStackY_1e8;
  if ((param_1 == 0) || (param_2 == 0)) {
    return -0x3ffffff3;
  }
  puVar3 = *(undefined4 **)(param_2 + 0x18);
  local_1a8 = *(undefined1 (*) [16])(puVar3 + 2);
  uVar15 = local_1a8._0_4_;
  uVar16 = local_1a8._4_4_;
  uVar17 = local_1a8._8_4_;
  uVar18 = local_1a8._12_4_;
  uVar2 = *puVar3;
  uVar39 = puVar3[0x1a];
  uVar40 = puVar3[0x1b];
  uVar41 = puVar3[0x1c];
  uVar42 = puVar3[0x1d];
  local_198 = *(undefined1 (*) [16])(puVar3 + 6);
  uVar23 = local_198._0_4_;
  uVar24 = local_198._4_4_;
  uVar25 = local_198._8_4_;
  uVar26 = local_198._12_4_;
  local_188 = *(undefined1 (*) [16])(puVar3 + 10);
  uVar27 = local_188._0_4_;
  uVar28 = local_188._4_4_;
  uVar29 = local_188._8_4_;
  uVar30 = local_188._12_4_;
  local_178 = *(undefined1 (*) [16])(puVar3 + 0xe);
  uVar19 = local_178._0_4_;
  uVar20 = local_178._4_4_;
  uVar21 = local_178._8_4_;
  uVar22 = local_178._12_4_;
  uVar31 = puVar3[0x12];
  uVar32 = puVar3[0x13];
  uVar33 = puVar3[0x14];
  uVar34 = puVar3[0x15];
  uVar35 = puVar3[0x16];
  uVar36 = puVar3[0x17];
  uVar37 = puVar3[0x18];
  uVar38 = puVar3[0x19];
  uVar14 = local_1a8._8_8_;
  uVar13 = local_198._8_8_;
  uVar5 = local_188._0_8_;
  lVar12 = local_178._0_8_;
  local_168 = uVar31;
  uStack_164 = uVar32;
  uStack_160 = uVar33;
  uStack_15c = uVar34;
  local_158 = uVar35;
  uStack_154 = uVar36;
  uStack_150 = uVar37;
  uStack_14c = uVar38;
  local_148 = uVar39;
  uStack_144 = uVar40;
  uStack_140 = uVar41;
  uStack_13c = uVar42;
  switch(uVar2) {
  case 0:
    if (uVar15 == 0) {
      iVar9 = 0xcd;
      break;
    }
    local_b8[0] = (ulonglong)uVar15;
    local_b8[1] = 0;
    local_118 = 0x30;
    local_100 = 0;
    local_110 = 0;
    local_108 = 0;
    local_1b0 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    if (DAT_140009108 == 0) {
      local_d8 = local_d8 & 0xffffff00;
      local_1b8 = 0;
      local_e8[0] = 0xb2;
      local_e8[1] = 0x96;
      local_e8[2] = 0xa1;
      local_e8[3] = 0x83;
      local_e8[4] = 0x95;
      local_e8[5] = 0x83;
      local_e8[6] = 0xa6;
      local_e8[7] = 0x81;
      local_e8[8] = 0x87;
      local_e8[9] = 0x92;
      local_e8[10] = 0x9f;
      local_e8[0xb] = 0x8c;
      local_e8[0xc] = 0x8f;
      local_e8[0xd] = 0x79;
      local_e8[0xe] = 0;
      local_e8[0xf] = 0;
      do {
        bVar1 = local_e8[local_1b8];
        local_e8[local_1b8] =
             (char)local_1b8 + ((char)local_1b8 + 0xaeU & bVar1) * -2 + -0x14 + bVar1;
        local_1b8 = local_1b8 + 1;
      } while (local_1b8 < 0x11);
      DAT_140009108 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_e8);
      if (DAT_140009108 == 0) goto LAB_1400011d5;
    }
    iVar9 = (*(code *)DAT_140009108)(&local_1b0,0x1fffff,&local_118,local_b8);
    auVar6 = local_178;
    if ((iVar9 == 0) && (local_1b0 != 0)) {
      local_178._0_4_ = (undefined4)local_1b0;
      local_178._4_4_ = (undefined4)((ulonglong)local_1b0 >> 0x20);
      local_178._8_4_ = auVar6._8_4_;
      local_178._12_4_ = auVar6._12_4_;
      uVar19 = local_178._0_4_;
      uVar20 = local_178._4_4_;
      uVar21 = local_178._8_4_;
      uVar22 = local_178._12_4_;
      iVar9 = 0;
    }
    break;
  case 1:
    lVar12 = 0;
    if (DAT_1400091d0 == 0) {
      local_b8[2] = DAT_1400091d0;
      local_a0 = 0;
      local_9c = 0;
      local_b8[0] = 0xeeee8deefc99ec86;
      local_b8[1] = 0x27868a8ae6e5f6f3;
      local_1b8 = 0;
      do {
        *(byte *)((longlong)local_b8 + local_1b8) =
             (char)local_1b8 +
             ((char)local_1b8 + 0xb3U & *(byte *)((longlong)local_b8 + local_1b8)) * -2 + -0x32 +
             *(byte *)((longlong)local_b8 + local_1b8);
        local_1b8 = local_1b8 + 1;
      } while (local_1b8 < 0x1e);
      DAT_1400091d0 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_b8);
      if (DAT_1400091d0 != 0) goto LAB_14000147f;
    }
    else {
LAB_14000147f:
      lVar12 = (*(code *)DAT_1400091d0)(uVar13);
    }
    local_178._8_4_ = (undefined4)lVar12;
    local_178._12_4_ = (undefined4)((ulonglong)lVar12 >> 0x20);
    uVar19 = local_178._0_4_;
    uVar20 = local_178._4_4_;
    uVar21 = local_178._8_4_;
    uVar22 = local_178._12_4_;
    iVar9 = -0x3fffffff;
    if (lVar12 != 0) {
      iVar9 = 0;
    }
    break;
  case 2:
    lVar10 = FUN_1400035c0(&DAT_1400050b0,uVar14,(undefined4 *)0x0);
    if (lVar10 != 0) {
      local_1b0 = 0;
      uVar14 = 0x1000 - (ulonglong)((uint)lVar10 & 0xfff);
      if (uVar5 <= uVar14) {
        uVar14 = uVar5;
      }
      iVar8 = FUN_140002bb0(lVar12,lVar10,uVar14,1,&local_1b0);
      iVar9 = -0x3fffffff;
      if (iVar8 != 0) {
        iVar9 = 0;
      }
      break;
    }
    goto LAB_1400011d5;
  case 3:
    lVar10 = FUN_1400035c0(&DAT_1400050b0,uVar14,(undefined4 *)0x0);
    if (lVar10 != 0) {
      uVar14 = 0x1000 - (ulonglong)((uint)lVar10 & 0xfff);
      if (uVar5 <= uVar14) {
        uVar14 = uVar5;
      }
      uVar13 = FUN_1400037f0(lVar10,lVar12,uVar14);
      iVar9 = 0xc5;
      if ((char)uVar13 != '\0') {
        iVar9 = 0;
      }
      break;
    }
LAB_1400011d5:
    iVar9 = -0x3fffffff;
    break;
  case 4:
    uVar11 = FUN_140001ff0((int *)local_1a8);
    uVar13 = local_1a8._0_8_;
    uVar15 = local_1a8._0_4_;
    uVar16 = local_1a8._4_4_;
    uVar17 = local_1a8._8_4_;
    uVar18 = local_1a8._12_4_;
    uVar19 = local_178._0_4_;
    uVar20 = local_178._4_4_;
    uVar21 = local_178._8_4_;
    uVar22 = local_178._12_4_;
    uVar23 = local_198._0_4_;
    uVar24 = local_198._4_4_;
    uVar25 = local_198._8_4_;
    uVar26 = local_198._12_4_;
    uVar27 = local_188._0_4_;
    uVar28 = local_188._4_4_;
    uVar29 = local_188._8_4_;
    uVar30 = local_188._12_4_;
    uVar31 = local_168;
    uVar32 = uStack_164;
    uVar33 = uStack_160;
    uVar34 = uStack_15c;
    uVar35 = local_158;
    uVar36 = uStack_154;
    uVar37 = uStack_150;
    uVar38 = uStack_14c;
    uVar39 = local_148;
    uVar40 = uStack_144;
    uVar41 = uStack_140;
    uVar42 = uStack_13c;
    iVar9 = (int)uVar11;
    local_1a8._0_8_ = uVar13;
    break;
  case 5:
    lVar12 = 0;
    if (DAT_1400091c0 == 0) {
      local_c9 = DAT_1400091c0;
      local_c1 = 0;
      local_bd = 0;
      local_bb = 0;
      local_1b8 = 0;
      local_e8[0] = 0x40;
      local_e8[1] = 0x22;
      local_e8[2] = 0x75;
      local_e8[3] = 0x56;
      local_e8[4] = 0x20;
      local_e8[5] = 0x45;
      local_e8[6] = 0x24;
      local_e8[7] = 0x28;
      local_e8[8] = 0x4b;
      local_e8[9] = 0x4c;
      local_e8[10] = 0x39;
      local_e8[0xb] = 0x38;
      local_e8[0xc] = 0x5f;
      local_e8[0xd] = 0x48;
      local_e8[0xe] = 0x4d;
      local_e8[0xf] = 0x3b;
      local_d8 = 0x613c3e39;
      local_d4 = 0x66433645;
      local_d0 = 0xbec8bdbc;
      local_cc = 0xcecf;
      local_ca = 0x5e;
      do {
        bVar1 = local_e8[local_1b8];
        local_e8[local_1b8] =
             (char)local_1b8 + ((char)local_1b8 - 0x18U & bVar1) * -2 + -0x70 + bVar1;
        local_1b8 = local_1b8 + 1;
      } while (local_1b8 < 0x2e);
      DAT_1400091c0 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_e8);
      if (DAT_1400091c0 != 0) goto LAB_14000157f;
    }
    else {
LAB_14000157f:
      lVar12 = (*(code *)DAT_1400091c0)(uVar13);
    }
    local_1a8._8_4_ = (undefined4)lVar12;
    local_1a8._12_4_ = (undefined4)((ulonglong)lVar12 >> 0x20);
    uVar15 = local_1a8._0_4_;
    uVar16 = local_1a8._4_4_;
    uVar17 = local_1a8._8_4_;
    uVar18 = local_1a8._12_4_;
    iVar9 = -0x3fffffff;
    if (lVar12 != 0) {
      iVar9 = 0;
    }
    break;
  case 6:
    local_1b8 = local_1b8 & 0xffffffff00000000;
    lVar12 = FUN_1400035c0(&DAT_1400050b0,uVar14,(undefined4 *)&local_1b8);
    auVar7 = local_188;
    auVar6 = local_198;
    local_188._0_4_ = (undefined4)local_1b8;
    local_188._4_4_ = 0;
    local_188._8_4_ = auVar7._8_4_;
    local_188._12_4_ = auVar7._12_4_;
    iVar9 = -0x3fffffff;
    if (lVar12 != 0) {
      iVar9 = 0;
    }
    local_198._0_4_ = (undefined4)lVar12;
    local_198._4_4_ = (undefined4)((ulonglong)lVar12 >> 0x20);
    local_198._8_4_ = auVar6._8_4_;
    local_198._12_4_ = auVar6._12_4_;
    uVar23 = local_198._0_4_;
    uVar24 = local_198._4_4_;
    uVar25 = local_198._8_4_;
    uVar26 = local_198._12_4_;
    uVar27 = local_188._0_4_;
    uVar28 = local_188._4_4_;
    uVar29 = local_188._8_4_;
    uVar30 = local_188._12_4_;
    break;
  default:
    iVar9 = -0x3ffffff3;
    break;
  case 8:
    uVar13 = FUN_1400033d0(&DAT_1400050b0,uVar14);
    auVar6 = local_198;
    if ((char)uVar13 != '\0') {
      local_198._0_8_ = DAT_1400050b0;
    }
    local_198._4_4_ = (undefined4)((ulonglong)local_198._0_8_ >> 0x20);
    local_198._8_4_ = auVar6._8_4_;
    local_198._12_4_ = auVar6._12_4_;
    uVar23 = local_198._0_4_;
    uVar24 = local_198._4_4_;
    uVar25 = local_198._8_4_;
    uVar26 = local_198._12_4_;
    iVar9 = -0x3fffffff;
    if ((char)uVar13 != '\0') {
      iVar9 = 0;
    }
  }
  puVar4 = *(undefined8 **)(param_2 + 0x18);
  local_1a8._8_4_ = uVar15;
  local_1a8._12_4_ = uVar16;
  auVar6 = local_1a8;
  local_198._4_4_ = uVar18;
  local_198._0_4_ = uVar17;
  local_1a8._0_4_ = uVar2;
  auVar7 = local_1a8;
  local_1a8._8_8_ = auVar6._8_8_;
  *puVar4 = local_1a8._0_8_;
  puVar4[1] = local_1a8._8_8_;
  uStack_130 = 1;
  local_198._8_4_ = uVar23;
  local_198._12_4_ = uVar24;
  local_188._4_4_ = uVar26;
  local_188._0_4_ = uVar25;
  puVar4[2] = local_198._0_8_;
  puVar4[3] = local_198._8_8_;
  local_188._8_4_ = uVar27;
  local_188._12_4_ = uVar28;
  local_178._4_4_ = uVar30;
  local_178._0_4_ = uVar29;
  puVar4[4] = local_188._0_8_;
  puVar4[5] = local_188._8_8_;
  local_178._8_4_ = uVar19;
  local_178._12_4_ = uVar20;
  puVar4[6] = local_178._0_8_;
  puVar4[7] = local_178._8_8_;
  puVar4[8] = CONCAT44(uVar22,uVar21);
  puVar4[9] = CONCAT44(uVar32,uVar31);
  puVar4[10] = CONCAT44(uVar34,uVar33);
  puVar4[0xb] = CONCAT44(uVar36,uVar35);
  puVar4[0xc] = CONCAT44(uVar38,uVar37);
  puVar4[0xd] = CONCAT44(uVar40,uVar39);
  puVar4[0xe] = CONCAT44(uVar42,uVar41);
  puVar4[0xf] = CONCAT71(uStack_12f,1);
  puVar4[0x10] = local_128;
  puVar4[0x11] = CONCAT44(uStack_11c,iVar9);
  *(int *)(param_2 + 0x30) = iVar9;
  *(undefined8 *)(param_2 + 0x38) = 0x90;
  local_1a8 = auVar7;
  local_168 = uVar21;
  uStack_164 = uVar22;
  uStack_160 = uVar31;
  uStack_15c = uVar32;
  local_158 = uVar33;
  uStack_154 = uVar34;
  uStack_150 = uVar35;
  uStack_14c = uVar36;
  local_148 = uVar37;
  uStack_144 = uVar38;
  uStack_140 = uVar39;
  uStack_13c = uVar40;
  local_138 = uVar41;
  uStack_134 = uVar42;
  iStack_120 = iVar9;
  FUN_140002980(param_2,0);
  return iVar9;
}



// WARNING: Function: __chkstk replaced with injection: alloca_probe
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

ulonglong FUN_140001770(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  ulonglong uVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined1 auStackY_10b8 [32];
  ulonglong local_1088;
  ulonglong local_1080;
  ulonglong local_1078;
  ulonglong local_1070;
  byte local_1068 [32];
  ulonglong local_1048 [512];
  ulonglong local_48;
  undefined8 uStack_40;
  
  uStack_40 = 0x140001792;
  local_48 = DAT_140005000 ^ (ulonglong)auStackY_10b8;
  FUN_140003c80((longlong *)local_1048,0,(undefined1 *)0x1000);
  local_1088 = 0;
  uVar1 = FUN_140002bb0(local_1048,param_2,0x1000,1,&local_1088);
  if ((int)uVar1 != 0) {
LAB_140001a22:
    return uVar1 & 0xffffffffffffff00;
  }
  uVar1 = local_1048[param_3 >> 0x27 & 0x1ff];
  if ((uVar1 & 1) == 0) goto LAB_140001a22;
  local_1080 = 0;
  local_1088 = 0;
  uVar1 = FUN_140002bb0(&local_1080,(uVar1 & 0xfffffffff000) + (param_3 >> 0x1e & 0x1ff) * 8,8,1,
                        &local_1088);
  if (((int)uVar1 != 0) || (uVar1 = local_1080, (local_1080 & 1) == 0)) goto LAB_140001a22;
  local_1078 = 0;
  local_1088 = 0;
  uVar1 = FUN_140002bb0(&local_1078,(local_1080 & 0xfffffffff000) + (param_3 >> 0x15 & 0x1ff) * 8,8,
                        1,&local_1088);
  if (((int)uVar1 != 0) || (uVar1 = local_1078, (local_1078 & 1) == 0)) goto LAB_140001a22;
  local_1070 = 0;
  local_1088 = 0;
  uVar1 = FUN_140002bb0(&local_1070,(local_1078 & 0xfffffffff000) + (param_3 >> 0xc & 0x1ff) * 8,8,1
                        ,&local_1088);
  if (((int)uVar1 != 0) || ((local_1070 & 1) == 0)) goto LAB_140001a22;
  FUN_1400032d0(param_1 + 0x10,*(longlong *)(param_1 + 0x1010) << 3);
  pcVar2 = (code *)DAT_140009150;
  *(undefined8 *)(param_1 + 0x1010) = 0;
  if (pcVar2 == (code *)0x0) {
    local_1068[0xe] = 0;
    local_1068[0xf] = 0;
    local_1068[0x10] = 0;
    local_1068[0x11] = 0;
    local_1088 = 0;
    local_1068[0] = 0xd4;
    local_1068[1] = 0x2d;
    local_1068[2] = 0x34;
    local_1068[3] = 0xde;
    local_1068[4] = 0x33;
    local_1068[5] = 0x4d;
    local_1068[6] = 0x57;
    local_1068[7] = 0xa8;
    local_1068[8] = 0x41;
    local_1068[9] = 0x4e;
    local_1068[10] = 0x49;
    local_1068[0xb] = 0x49;
    local_1068[0xc] = 0x51;
    local_1068[0xd] = 0xd5;
    do {
      local_1068[local_1088] =
           (char)local_1088 + ((char)local_1088 + 0x3bU & local_1068[local_1088]) * -2 + -0x62 +
           local_1068[local_1088];
      local_1088 = local_1088 + 1;
    } while (local_1088 < 0x12);
    pcVar2 = (code *)FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_1068);
    uVar3 = 0;
    DAT_140009150 = (longlong)pcVar2;
    if (pcVar2 == (code *)0x0) goto LAB_1400019f0;
  }
  uVar3 = (*pcVar2)(param_1 + 0x10,local_1048,0x1000);
LAB_1400019f0:
  *(longlong *)(param_1 + 0x1010) = *(longlong *)(param_1 + 0x1010) + 0x200;
  *(ushort *)(param_1 + 0x4050) = (ushort)(param_3 >> 0x27) & 0x1ff;
  *(ushort *)(param_1 + 0x4052) = (ushort)(param_3 >> 0x1e) & 0x1ff;
  *(ushort *)(param_1 + 0x4054) = (ushort)(param_3 >> 0x15) & 0x1ff;
  return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

ulonglong FUN_140001a50(undefined *param_1)

{
  undefined4 *puVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  short sVar5;
  undefined1 auStack_1b8 [32];
  undefined8 local_198;
  undefined4 local_190;
  undefined4 local_188;
  undefined4 local_180;
  undefined4 **local_178;
  undefined4 *local_168;
  undefined4 local_160 [2];
  undefined4 *local_158;
  undefined4 local_150 [2];
  undefined8 local_148;
  undefined4 *local_140;
  undefined4 local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  byte local_118 [29];
  longlong local_fb;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined4 local_dc;
  short local_d8;
  short local_d6;
  short local_d4;
  short local_d2;
  short local_d0;
  short local_ce;
  short local_cc;
  short local_ca;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_1b8;
  FUN_140003c80(&local_e8,0,(undefined1 *)0xc8);
  uVar2 = 0;
  if (DAT_140009148 == 0) {
    local_fb = DAT_140009148;
    local_168 = (undefined4 *)0x0;
    local_118[0] = 0x23;
    local_118[1] = 8;
    local_118[2] = 0x23;
    local_118[3] = 6;
    local_118[4] = 0x15;
    local_118[5] = 7;
    local_118[6] = 0xf;
    local_118[7] = 0x22;
    local_118[8] = 6;
    local_118[9] = 0x13;
    local_118[10] = 0x13;
    local_118[0xb] = 0x1a;
    local_118[0xc] = 0xf;
    local_118[0xd] = 0x1c;
    local_118[0xe] = 0x1a;
    local_118[0xf] = 0x36;
    local_118[0x10] = 0xe;
    local_118[0x11] = 9;
    local_118[0x12] = 0xe7;
    local_118[0x13] = 0xf5;
    local_118[0x14] = 0xf6;
    local_118[0x15] = 0xf4;
    local_118[0x16] = 0xf6;
    local_118[0x17] = 0xf3;
    local_118[0x18] = 0xd0;
    local_118[0x19] = 0xec;
    local_118[0x1a] = 0xe7;
    local_118[0x1b] = 0xee;
    local_118[0x1c] = 0x88;
    do {
      local_118[(longlong)local_168] =
           ('6' - ((char)local_168 + 0x6eU & local_118[(longlong)local_168])) * '\x02' +
           (char)local_168 + local_118[(longlong)local_168];
      local_168 = (undefined4 *)((longlong)local_168 + 1);
    } while (local_168 < (undefined4 *)0x25);
    DAT_140009148 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_118);
    if (DAT_140009148 == 0) goto LAB_140001b5f;
  }
  uVar2 = (*(code *)DAT_140009148)();
LAB_140001b5f:
  local_d8 = 0x30;
  local_e8._0_4_ = 0x44005c;
  local_e8._4_4_ = 0x690072;
  uVar3 = (uint)(uVar2 >> 0x1c) & 0xf;
  local_e0 = 0x650076;
  local_dc = 0x5c0072;
  local_160[0] = 0x220020;
  if (9 < uVar3) {
    local_d8 = 0x37;
  }
  local_150[0] = 0x30;
  local_d8 = local_d8 + (short)uVar3;
  local_148 = 0;
  uVar3 = (uint)(uVar2 >> 0x18) & 0xf;
  local_138 = 0x240;
  local_168 = (undefined4 *)0x0;
  local_130 = 0;
  uStack_128 = 0;
  local_d6 = 0x30;
  if (9 < uVar3) {
    local_d6 = 0x37;
  }
  local_d6 = local_d6 + (short)uVar3;
  local_d4 = 0x30;
  uVar3 = (uint)(uVar2 >> 0x14) & 0xf;
  sVar5 = 0x37;
  if (9 < uVar3) {
    local_d4 = 0x37;
  }
  local_d4 = local_d4 + (short)uVar3;
  uVar3 = (uint)(uVar2 >> 0x10) & 0xf;
  local_d2 = 0x30;
  if (9 < uVar3) {
    local_d2 = sVar5;
  }
  local_d2 = local_d2 + (short)uVar3;
  uVar3 = (uint)(uVar2 >> 0xc) & 0xf;
  local_d0 = 0x30;
  if (9 < uVar3) {
    local_d0 = sVar5;
  }
  local_d0 = local_d0 + (short)uVar3;
  uVar3 = (uint)(uVar2 >> 8) & 0xf;
  local_ce = 0x30;
  if (9 < uVar3) {
    local_ce = sVar5;
  }
  local_ce = local_ce + (short)uVar3;
  local_cc = 0x30;
  uVar3 = (uint)(uVar2 >> 4) & 0xf;
  if (9 < uVar3) {
    local_cc = 0x37;
  }
  uVar4 = (uint)uVar2 & 0xf;
  local_cc = local_cc + (short)uVar3;
  local_ca = 0x30;
  if (9 < uVar4) {
    local_ca = 0x37;
  }
  local_ca = local_ca + (short)uVar4;
  local_158 = (undefined4 *)&local_e8;
  local_140 = local_160;
  local_178 = &local_168;
  local_180 = 0;
  local_188 = 0;
  local_190 = 0x1a0;
  local_198 = 0;
  uVar2 = ObCreateObject(0,*(undefined8 *)IoDriverObjectType_exref,local_150,0);
  puVar1 = local_168;
  if (((int)uVar2 == 0) && (local_168 != (undefined4 *)0x0)) {
    FUN_1400032d0(local_168,0x1a0);
    *puVar1 = 0x1500004;
    puVar1[4] = 2;
    *(undefined4 **)(puVar1 + 0xc) = puVar1 + 0x54;
    if (puVar1 + 0x54 == (undefined4 *)0x0) {
      FUN_140002fc0(puVar1);
      FUN_140002ed0(puVar1);
      uVar2 = 0xc9a;
    }
    else {
      *(undefined8 *)(puVar1 + 0x1c) = 0;
      *(undefined8 *)(puVar1 + 0x1e) = 0;
      *(undefined8 *)(puVar1 + 0x20) = 0;
      *(undefined8 *)(puVar1 + 0x22) = 0;
      *(undefined8 *)(puVar1 + 0x24) = 0;
      *(undefined8 *)(puVar1 + 0x26) = 0;
      *(undefined8 *)(puVar1 + 0x28) = 0;
      *(undefined8 *)(puVar1 + 0x2a) = 0;
      *(undefined8 *)(puVar1 + 0x2c) = 0;
      *(undefined8 *)(puVar1 + 0x2e) = 0;
      *(undefined8 *)(puVar1 + 0x30) = 0;
      *(undefined8 *)(puVar1 + 0x32) = 0;
      *(undefined8 *)(puVar1 + 0x34) = 0;
      *(undefined8 *)(puVar1 + 0x36) = 0;
      *(undefined8 *)(puVar1 + 0x38) = 0;
      *(undefined8 *)(puVar1 + 0x3a) = 0;
      *(undefined8 *)(puVar1 + 0x3c) = 0;
      *(undefined8 *)(puVar1 + 0x3e) = 0;
      *(undefined8 *)(puVar1 + 0x40) = 0;
      *(undefined8 *)(puVar1 + 0x42) = 0;
      *(undefined8 *)(puVar1 + 0x44) = 0;
      *(undefined8 *)(puVar1 + 0x46) = 0;
      *(undefined8 *)(puVar1 + 0x48) = 0;
      *(undefined8 *)(puVar1 + 0x4a) = 0;
      *(undefined8 *)(puVar1 + 0x4c) = 0;
      *(undefined8 *)(puVar1 + 0x4e) = 0;
      *(undefined8 *)(puVar1 + 0x50) = 0;
      *(undefined8 *)(puVar1 + 0x52) = 0;
      uVar3 = (*(code *)param_1)(puVar1,0);
      *(undefined2 *)(puVar1 + 0xe) = 0;
      uVar2 = (ulonglong)uVar3;
      *(undefined8 *)(puVar1 + 10) = 0;
      FUN_140002fc0(puVar1);
      FUN_140002ed0(puVar1);
    }
  }
  return uVar2;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Globals starting with '_' overlap smaller symbols at the same address

ulonglong entry(void)

{
  ulonglong uVar1;
  undefined1 auStack_78 [32];
  char *local_58;
  byte local_48 [31];
  char *local_29;
  undefined2 local_21;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  _DAT_140005080 = FUN_140001060();
  if ((_DAT_140005080 != 0) && (DAT_1400060c0 == 0)) {
    if (DAT_140009188 == 0) {
      if (DAT_140009190 == (char *)0x0) {
        local_58 = DAT_140009190;
        local_29 = DAT_140009190;
        local_21 = 0;
        local_48[0] = 0x83;
        local_48[1] = 0xa8;
        local_48[2] = 0xb5;
        local_48[3] = 0x92;
        local_48[4] = 0x60;
        local_48[5] = 0x65;
        local_48[6] = 99;
        local_48[7] = 0x61;
        local_48[8] = 0x91;
        local_48[9] = 0x85;
        local_48[10] = 0x9f;
        local_48[0xb] = 0x6d;
        local_48[0xc] = 0x6f;
        local_48[0xd] = 0x90;
        local_48[0xe] = 0x69;
        local_48[0xf] = 0x6b;
        local_48[0x10] = 0x99;
        local_48[0x11] = 0x6f;
        local_48[0x12] = 0x76;
        local_48[0x13] = 0x97;
        local_48[0x14] = 0x88;
        local_48[0x15] = 0x77;
        local_48[0x16] = 0x83;
        local_48[0x17] = 0x86;
        local_48[0x18] = 0x80;
        local_48[0x19] = 0x92;
        local_48[0x1a] = 0x7e;
        local_48[0x1b] = 0x8a;
        local_48[0x1c] = 0x7c;
        local_48[0x1d] = 0x8c;
        local_48[0x1e] = 0xee;
        do {
          local_48[(longlong)local_58] =
               (char)local_58 + ((char)local_58 + 0x5eU & local_48[(longlong)local_58]) * -2 + -0x34
               + local_48[(longlong)local_58];
          local_58 = local_58 + 1;
        } while (local_58 < (char *)0x29);
        DAT_140009190 = (char *)FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
        if (DAT_140009190 == (char *)0x0) {
          _DAT_1400050b8 = 0;
          return 0xc00000bb;
        }
      }
      for (; ((*DAT_140009190 != 'H' || (DAT_140009190[1] != -0x75)) || (DAT_140009190[2] != '\x05')
             ); DAT_140009190 = DAT_140009190 + 1) {
      }
      DAT_140009188 = *(longlong *)(DAT_140009190 + (longlong)*(int *)(DAT_140009190 + 3) + 7);
    }
    _DAT_1400050b8 = DAT_140009188;
    if (DAT_140009188 != 0) {
      DbgPrint("Driver loaded successfully.\n");
      FUN_140002290();
      uVar1 = FUN_140001a50(FUN_140002450);
      return uVar1;
    }
  }
  return 0xc00000bb;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

undefined8 FUN_140001ff0(int *param_1)

{
  int iVar1;
  undefined8 *puVar2;
  char cVar3;
  int iVar4;
  undefined8 *puVar5;
  longlong lVar6;
  undefined8 uVar7;
  longlong lVar8;
  undefined1 auStack_78 [32];
  ulonglong local_58;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_39;
  ulonglong local_28;
  
  local_28 = DAT_140005000 ^ (ulonglong)auStack_78;
  iVar1 = *param_1;
  puVar5 = (undefined8 *)FUN_1400030b0();
  if (puVar5 == (undefined8 *)0x0) {
    lVar8 = 0;
  }
  else {
    lVar6 = FUN_1400031e0();
    if ((longlong)puVar5 - lVar6 != 0) {
      puVar2 = (undefined8 *)*puVar5;
      while ((puVar2 != (undefined8 *)0x0 && (cVar3 = FUN_140002cd0(puVar2), cVar3 != '\0'))) {
        lVar8 = (longlong)puVar2 - ((longlong)puVar5 - lVar6);
        if (lVar8 != 0) {
          if (DAT_1400091a8 == 0) {
            local_58 = 0;
            local_39 = 0;
            local_48 = 0xc8edb8e6;
            local_44 = 0x3ebee1be;
            local_40 = 0x46413633;
            local_3c = 0x351d;
            local_3a = 200;
            do {
              *(byte *)((longlong)&local_48 + local_58) =
                   ('\x15' - ((char)local_58 - 7U & *(byte *)((longlong)&local_48 + local_58))) *
                   '\x02' + (char)local_58 + *(byte *)((longlong)&local_48 + local_58);
              local_58 = local_58 + 1;
            } while (local_58 < 0x13);
            DAT_1400091a8 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)&local_48);
            if (DAT_1400091a8 != 0) goto LAB_140002126;
            iVar4 = 0;
          }
          else {
LAB_140002126:
            iVar4 = (*(code *)DAT_1400091a8)(lVar8);
          }
          if (iVar4 == iVar1) goto LAB_14000214b;
        }
        puVar2 = (undefined8 *)*puVar2;
      }
    }
    lVar8 = 0;
  }
LAB_14000214b:
  *(longlong *)(param_1 + 6) = lVar8;
  uVar7 = 0xc0000001;
  if (lVar8 != 0) {
    uVar7 = 0;
  }
  return uVar7;
}



longlong FUN_140002180(undefined8 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  longlong lVar8;
  char *pcVar9;
  char *pcVar10;
  int *piVar11;
  int iVar12;
  short *psVar13;
  
  psVar7 = (short *)*param_1;
  lVar8 = (longlong)*(int *)(psVar7 + 0x1e);
  if (((*psVar7 == 0x5a4d) && (*(int *)(lVar8 + (longlong)psVar7) == 0x4550)) &&
     (*(short *)(lVar8 + 0x18 + (longlong)psVar7) == 0x20b)) {
    lVar8 = (longlong)*(int *)(lVar8 + 0x88 + (longlong)psVar7);
    iVar3 = *(int *)(lVar8 + 0x1c + (longlong)psVar7);
    if (((iVar3 != 0) && (iVar4 = *(int *)(lVar8 + 0x20 + (longlong)psVar7), iVar4 != 0)) &&
       (iVar5 = *(int *)(lVar8 + 0x24 + (longlong)psVar7), iVar5 != 0)) {
      iVar6 = *(int *)(lVar8 + 0x18 + (longlong)psVar7);
      iVar12 = 0;
      piVar11 = (int *)((longlong)psVar7 + (longlong)iVar4);
      psVar13 = (short *)((longlong)psVar7 + (longlong)iVar5);
      if (0 < iVar6) {
        do {
          pcVar9 = (char *)((longlong)*piVar11 + (longlong)psVar7);
          if ((pcVar9 != (char *)0x0) &&
             (lVar8 = (longlong)
                      *(int *)((longlong)psVar7 + (longlong)*psVar13 * 4 + (longlong)iVar3) +
                      (longlong)psVar7, lVar8 != 0)) {
            cVar2 = *param_2;
            pcVar10 = param_2;
            while ((cVar2 != '\0' && (cVar2 == *pcVar9))) {
              pcVar1 = pcVar10 + 1;
              pcVar10 = pcVar10 + 1;
              pcVar9 = pcVar9 + 1;
              cVar2 = *pcVar1;
            }
            if (*pcVar10 == *pcVar9) {
              return lVar8;
            }
          }
          iVar12 = iVar12 + 1;
          piVar11 = piVar11 + 1;
          psVar13 = psVar13 + 1;
        } while (iVar12 < iVar6);
      }
    }
  }
  return 0;
}



undefined4 FUN_140002270(undefined8 param_1,longlong param_2)

{
  FUN_140002980(param_2,0);
  return *(undefined4 *)(param_2 + 0x30);
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_140002290(void)

{
  undefined1 auStack_78 [32];
  ulonglong local_58;
  byte local_48 [37];
  ulonglong local_23;
  undefined1 local_1b;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_140009110 == 0) {
    local_58 = DAT_140009110;
    local_23 = DAT_140009110;
    local_1b = 0;
    local_48[0x15] = 0;
    local_48[0x16] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0x1b] = 0;
    local_48[0x1c] = 0;
    local_48[0x1d] = 0;
    local_48[0x1e] = 0;
    local_48[0x1f] = 0;
    local_48[0x20] = 0;
    local_48[0x21] = 0;
    local_48[0x22] = 0;
    local_48[0x23] = 0;
    local_48[0x24] = 0;
    local_48[0] = 0x18;
    local_48[1] = 0x39;
    local_48[2] = 0;
    local_48[3] = 0xe4;
    local_48[4] = 0;
    local_48[5] = 6;
    local_48[6] = 0x3c;
    local_48[7] = 0x24;
    local_48[8] = 0x3c;
    local_48[9] = 0x3a;
    local_48[10] = 0x31;
    local_48[0xb] = 0x3a;
    local_48[0xc] = 0x36;
    local_48[0xd] = 0x32;
    local_48[0xe] = 0x25;
    local_48[0xf] = 0xb;
    local_48[0x10] = 8;
    local_48[0x11] = 0x32;
    local_48[0x12] = 0x36;
    local_48[0x13] = 0x3a;
    local_48[0x14] = 0x82;
    do {
      local_48[local_58] =
           ('5' - ((char)local_58 + 0x19U & local_48[local_58])) * '\x02' + (char)local_58 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x2e);
    DAT_140009110 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_140009110 != 0) goto LAB_14000235b;
  }
  else {
LAB_14000235b:
    (*(code *)DAT_140009110)(&DAT_140005090,L"\\Device\\{*discord_overlay*}");
    if (DAT_140009110 != 0) goto LAB_14000241b;
  }
  local_48[0] = 0x18;
  local_48[1] = 0x39;
  local_48[2] = 0;
  local_48[3] = 0xe4;
  local_58 = 0;
  local_23 = 0;
  local_1b = 0;
  local_48[4] = 0;
  local_48[5] = 6;
  local_48[6] = 0x3c;
  local_48[7] = 0x24;
  local_48[8] = 0x3c;
  local_48[9] = 0x3a;
  local_48[10] = 0x31;
  local_48[0xb] = 0x3a;
  local_48[0xc] = 0x36;
  local_48[0xd] = 0x32;
  local_48[0xe] = 0x25;
  local_48[0xf] = 0xb;
  local_48[0x10] = 8;
  local_48[0x11] = 0x32;
  local_48[0x12] = 0x36;
  local_48[0x13] = 0x3a;
  local_48[0x14] = 0x82;
  local_48[0x15] = 0;
  local_48[0x16] = 0;
  local_48[0x17] = 0;
  local_48[0x18] = 0;
  local_48[0x19] = 0;
  local_48[0x1a] = 0;
  local_48[0x1b] = 0;
  local_48[0x1c] = 0;
  local_48[0x1d] = 0;
  local_48[0x1e] = 0;
  local_48[0x1f] = 0;
  local_48[0x20] = 0;
  local_48[0x21] = 0;
  local_48[0x22] = 0;
  local_48[0x23] = 0;
  local_48[0x24] = 0;
  do {
    local_48[local_58] =
         ('5' - ((char)local_58 + 0x19U & local_48[local_58])) * '\x02' + (char)local_58 +
         local_48[local_58];
    local_58 = local_58 + 1;
  } while (local_58 < 0x2e);
  DAT_140009110 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
  if (DAT_140009110 == 0) {
    return;
  }
LAB_14000241b:
  (*(code *)DAT_140009110)(&DAT_1400050a0,L"\\GLOBAL??\\{*discord_overlay*}");
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

int FUN_140002450(longlong param_1)

{
  int iVar1;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined1 local_70;
  longlong *local_68;
  ulonglong local_58;
  longlong local_50;
  byte local_48 [37];
  ulonglong local_23;
  undefined2 local_1b;
  undefined1 local_19;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_98;
  FUN_140002880(&DAT_1400050a0);
  if (DAT_140009130 == 0) {
    local_58 = DAT_140009130;
    local_48[0xf] = 0;
    local_48[0x10] = 0;
    local_48[0x11] = 0;
    local_48[0x12] = 0;
    local_48[0x13] = 0;
    local_48[0x14] = 0;
    local_48[0x15] = 0;
    local_48[0x16] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0] = 0x29;
    local_48[1] = 0xc4;
    local_48[2] = 0x11;
    local_48[3] = 0xdd;
    local_48[4] = 0xd1;
    local_48[5] = 0x2e;
    local_48[6] = 0xdc;
    local_48[7] = 0xd4;
    local_48[8] = 10;
    local_48[9] = 0xd6;
    local_48[10] = 0xc6;
    local_48[0xb] = 0xdc;
    local_48[0xc] = 0x27;
    local_48[0xd] = 0xda;
    local_48[0xe] = 0x40;
    do {
      local_48[local_58] =
           ('\x19' - ((char)local_58 + 0x4dU & local_48[local_58])) * '\x02' + (char)local_58 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x1b);
    DAT_140009130 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_140009130 == 0) {
      return 0xc5;
    }
  }
  local_68 = &local_50;
  local_70 = 0;
  local_78 = 0x100;
  iVar1 = (*(code *)DAT_140009130)(param_1,0,&DAT_140005090,0x12);
  if (iVar1 == 0) {
    if (DAT_140009138 == 0) {
      local_58 = DAT_140009138;
      local_23 = DAT_140009138;
      local_1b = 0;
      local_19 = 0;
      local_48[0x15] = 0;
      local_48[0x16] = 0;
      local_48[0x17] = 0;
      local_48[0x18] = 0;
      local_48[0x19] = 0;
      local_48[0x1a] = 0;
      local_48[0x1b] = 0;
      local_48[0x1c] = 0;
      local_48[0x1d] = 0;
      local_48[0x1e] = 0;
      local_48[0x1f] = 0;
      local_48[0x20] = 0;
      local_48[0x21] = 0;
      local_48[0x22] = 0;
      local_48[0x23] = 0;
      local_48[0x24] = 0;
      local_48[0] = 0x11;
      local_48[1] = 0xf4;
      local_48[2] = 0x29;
      local_48[3] = 0xfd;
      local_48[4] = 9;
      local_48[5] = 0xe;
      local_48[6] = 0xfc;
      local_48[7] = 4;
      local_48[8] = 0x13;
      local_48[9] = 0xea;
      local_48[10] = 0xff;
      local_48[0xb] = 5;
      local_48[0xc] = 0xfb;
      local_48[0xd] = 0xfd;
      local_48[0xe] = 0xff;
      local_48[0xf] = 0xfa;
      local_48[0x10] = 0xe2;
      local_48[0x11] = 2;
      local_48[0x12] = 6;
      local_48[0x13] = 6;
      local_48[0x14] = 0x92;
      do {
        local_48[local_58] =
             ('-' - ((char)local_58 + 0x71U & local_48[local_58])) * '\x02' + (char)local_58 +
             local_48[local_58];
        local_58 = local_58 + 1;
      } while (local_58 < 0x30);
      DAT_140009138 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
      if (DAT_140009138 == 0) {
        FUN_140002770(*(undefined8 *)(param_1 + 8));
        return 0xc5;
      }
    }
    iVar1 = (*(code *)DAT_140009138)(&DAT_1400050a0,&DAT_140005090);
    if (iVar1 == 0) {
      *(code **)(param_1 + 0x70) = FUN_1400037c0;
      *(code **)(param_1 + 0x78) = FUN_1400037c0;
      *(code **)(param_1 + 0x80) = FUN_1400037c0;
      *(code **)(param_1 + 0x88) = FUN_1400037c0;
      *(code **)(param_1 + 0x90) = FUN_1400037c0;
      *(code **)(param_1 + 0x98) = FUN_1400037c0;
      *(code **)(param_1 + 0xa0) = FUN_1400037c0;
      *(code **)(param_1 + 0xa8) = FUN_1400037c0;
      *(code **)(param_1 + 0xb0) = FUN_1400037c0;
      *(code **)(param_1 + 0xb8) = FUN_1400037c0;
      *(code **)(param_1 + 0xc0) = FUN_1400037c0;
      *(code **)(param_1 + 200) = FUN_1400037c0;
      *(code **)(param_1 + 0xd0) = FUN_1400037c0;
      *(code **)(param_1 + 0xd8) = FUN_1400037c0;
      *(code **)(param_1 + 0xe0) = FUN_1400037c0;
      *(code **)(param_1 + 0xe8) = FUN_1400037c0;
      *(code **)(param_1 + 0xf0) = FUN_1400037c0;
      *(code **)(param_1 + 0xf8) = FUN_1400037c0;
      *(code **)(param_1 + 0x100) = FUN_1400037c0;
      *(code **)(param_1 + 0x108) = FUN_1400037c0;
      *(code **)(param_1 + 0x110) = FUN_1400037c0;
      *(code **)(param_1 + 0x118) = FUN_1400037c0;
      *(code **)(param_1 + 0x120) = FUN_1400037c0;
      *(code **)(param_1 + 0x128) = FUN_1400037c0;
      *(code **)(param_1 + 0x130) = FUN_1400037c0;
      *(code **)(param_1 + 0x138) = FUN_1400037c0;
      *(code **)(param_1 + 0x140) = FUN_1400037c0;
      *(uint *)(local_50 + 0x30) = *(uint *)(local_50 + 0x30) | 4;
      *(code **)(param_1 + 0x80) = FUN_140002270;
      *(code **)(param_1 + 0x70) = FUN_140002270;
      *(code **)(param_1 + 0xe0) = FUN_1400010e0;
      *(code **)(param_1 + 0x68) = FUN_140003790;
      *(uint *)(local_50 + 0x30) = *(uint *)(local_50 + 0x30) & 0xffffff7f;
      iVar1 = 0;
    }
    else {
      FUN_140002770(*(undefined8 *)(param_1 + 8));
    }
  }
  return iVar1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

undefined8 FUN_140002770(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 auStack_68 [32];
  ulonglong local_48;
  byte local_38 [15];
  ulonglong local_29;
  undefined4 local_21;
  undefined2 local_1d;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_68;
  if (DAT_140009128 == 0) {
    local_48 = DAT_140009128;
    local_29 = DAT_140009128;
    local_21 = 0;
    local_1d = 0;
    local_38[0] = 0xe1;
    local_38[1] = 0xc4;
    local_38[2] = 0xe8;
    local_38[3] = 200;
    local_38[4] = 0xc6;
    local_38[5] = 0xca;
    local_38[6] = 0xbc;
    local_38[7] = 0x34;
    local_38[8] = 0x12;
    local_38[9] = 0x36;
    local_38[10] = 0x46;
    local_38[0xb] = 0x3c;
    local_38[0xc] = 0x37;
    local_38[0xd] = 0x32;
    local_38[0xe] = 200;
    do {
      local_38[local_48] =
           ('\x15' - ((char)local_48 - 7U & local_38[local_48])) * '\x02' + (char)local_48 +
           local_38[local_48];
      local_48 = local_48 + 1;
    } while (local_48 < 0x1d);
    DAT_140009128 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_38);
    if (DAT_140009128 == 0) {
      return 0xc5;
    }
  }
  uVar1 = (*(code *)DAT_140009128)(param_1);
  return uVar1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

undefined8 FUN_140002880(undefined8 param_1)

{
  undefined8 uVar1;
  undefined1 auStack_78 [32];
  ulonglong local_58;
  byte local_48 [37];
  ulonglong local_23;
  undefined1 local_1b;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_140009120 == 0) {
    local_58 = DAT_140009120;
    local_23 = DAT_140009120;
    local_1b = 0;
    local_48[0x15] = 0;
    local_48[0x16] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0x1b] = 0;
    local_48[0x1c] = 0;
    local_48[0x1d] = 0;
    local_48[0x1e] = 0;
    local_48[0x1f] = 0;
    local_48[0x20] = 0;
    local_48[0x21] = 0;
    local_48[0x22] = 0;
    local_48[0x23] = 0;
    local_48[0x24] = 0;
    local_48[0] = 0xd1;
    local_48[1] = 0xf4;
    local_48[2] = 0x28;
    local_48[3] = 200;
    local_48[4] = 0xf6;
    local_48[5] = 0xca;
    local_48[6] = 0xfc;
    local_48[7] = 0xc4;
    local_48[8] = 0xd3;
    local_48[9] = 0xea;
    local_48[10] = 0xff;
    local_48[0xb] = 0xc5;
    local_48[0xc] = 0xfb;
    local_48[0xd] = 0xfd;
    local_48[0xe] = 0xff;
    local_48[0xf] = 0xfa;
    local_48[0x10] = 0xe2;
    local_48[0x11] = 0xc2;
    local_48[0x12] = 0xc6;
    local_48[0x13] = 0xc6;
    local_48[0x14] = 0x52;
    do {
      local_48[local_58] =
           ('\r' - ((char)local_58 + 0x51U & local_48[local_58])) * '\x02' + (char)local_58 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x2e);
    DAT_140009120 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_140009120 == 0) {
      return 0xc5;
    }
  }
  uVar1 = (*(code *)DAT_140009120)(param_1);
  return uVar1;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_140002980(undefined8 param_1,undefined1 param_2)

{
  undefined1 auStack_78 [32];
  ulonglong local_58;
  byte local_48 [48];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_140009118 == 0) {
    local_58 = DAT_140009118;
    local_48[0x23] = 0;
    local_48[0x24] = 0;
    local_48[0x25] = 0;
    local_48[0x26] = 0;
    local_48[0x27] = 0;
    local_48[0x28] = 0;
    local_48[0x29] = 0;
    local_48[0x13] = 0;
    local_48[0x14] = 0;
    local_48[0x15] = 0;
    local_48[0x16] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0x1b] = 0;
    local_48[0x1c] = 0;
    local_48[0x1d] = 0;
    local_48[0x1e] = 0;
    local_48[0x1f] = 0;
    local_48[0x20] = 0;
    local_48[0x21] = 0;
    local_48[0x22] = 0;
    local_48[0] = 0x1d;
    local_48[1] = 0xe0;
    local_48[2] = 0xfe;
    local_48[3] = 0x1e;
    local_48[4] = 0xe3;
    local_48[5] = 0xea;
    local_48[6] = 0xec;
    local_48[7] = 0xeb;
    local_48[8] = 0xf1;
    local_48[9] = 0xe5;
    local_48[10] = 0xf7;
    local_48[0xb] = 9;
    local_48[0xc] = 0xf5;
    local_48[0xd] = 0x16;
    local_48[0xe] = 0x1b;
    local_48[0xf] = 8;
    local_48[0x10] = 0x1b;
    local_48[0x11] = 0x1d;
    local_48[0x12] = 0xa0;
    do {
      local_48[local_58] =
           ('\'' - ((char)local_58 + 0x73U & local_48[local_58])) * '\x02' + (char)local_58 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x2a);
    DAT_140009118 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_140009118 == 0) {
      return;
    }
  }
  (*(code *)DAT_140009118)(param_1,param_2);
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_140002a90(undefined8 param_1)

{
  undefined1 auStack_78 [32];
  ulonglong local_58;
  byte local_48 [48];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_140009158 == 0) {
    local_58 = DAT_140009158;
    local_48[0x25] = 0;
    local_48[0x26] = 0;
    local_48[0x27] = 0;
    local_48[0x28] = 0;
    local_48[0x29] = 0;
    local_48[0x2a] = 0;
    local_48[0x2b] = 0;
    local_48[0x15] = 0;
    local_48[0x16] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0x1b] = 0;
    local_48[0x1c] = 0;
    local_48[0x1d] = 0;
    local_48[0x1e] = 0;
    local_48[0x1f] = 0;
    local_48[0x20] = 0;
    local_48[0x21] = 0;
    local_48[0x22] = 0;
    local_48[0x23] = 0;
    local_48[0x24] = 0;
    local_48[0] = 0x93;
    local_48[1] = 0xb4;
    local_48[2] = 0x93;
    local_48[3] = 0xcd;
    local_48[4] = 0xad;
    local_48[5] = 0xd9;
    local_48[6] = 0xaf;
    local_48[7] = 0xa6;
    local_48[8] = 0xd4;
    local_48[9] = 0xa8;
    local_48[10] = 0xd8;
    local_48[0xb] = 0xae;
    local_48[0xc] = 0xbf;
    local_48[0xd] = 0xdd;
    local_48[0xe] = 0xa7;
    local_48[0xf] = 0xd9;
    local_48[0x10] = 0xbc;
    local_48[0x11] = 0xde;
    local_48[0x12] = 0xa9;
    local_48[0x13] = 0xa0;
    local_48[0x14] = 0x74;
    do {
      local_48[local_58] =
           (char)local_58 + ((char)local_58 + 0x8cU & local_48[local_58]) * -2 + -0x48 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x2c);
    DAT_140009158 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_140009158 == 0) {
      return;
    }
  }
  (*(code *)DAT_140009158)(param_1);
  return;
}



undefined1 * FUN_140002b80(undefined1 *param_1,longlong param_2,longlong param_3)

{
  undefined1 *puVar1;
  
  if (param_3 != 0) {
    puVar1 = param_1;
    do {
      *puVar1 = puVar1[param_2 - (longlong)param_1];
      puVar1 = puVar1 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return param_1;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_140002bb0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
                  undefined8 param_5)

{
  undefined1 auStack_98 [32];
  undefined8 local_78;
  ulonglong local_68;
  byte local_58 [13];
  ulonglong local_4b;
  undefined2 local_43;
  undefined1 local_41;
  ulonglong local_38;
  
  local_38 = DAT_140005000 ^ (ulonglong)auStack_98;
  if (DAT_140009180 == 0) {
    local_68 = DAT_140009180;
    local_4b = DAT_140009180;
    local_43 = 0;
    local_41 = 0;
    local_58[0] = 0x79;
    local_58[1] = 0x16;
    local_58[2] = 0x7d;
    local_58[3] = 0x2a;
    local_58[4] = 0x2a;
    local_58[5] = 0x26;
    local_58[6] = 0x73;
    local_58[7] = 0x18;
    local_58[8] = 0x11;
    local_58[9] = 0x30;
    local_58[10] = 0x32;
    local_58[0xb] = 0x38;
    local_58[0xc] = 0xa2;
    do {
      local_58[local_68] =
           ('+' - ((char)local_68 + 0x47U & local_58[local_68])) * '\x02' + (char)local_68 +
           local_58[local_68];
      local_68 = local_68 + 1;
    } while (local_68 < 0x18);
    DAT_140009180 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_58);
    if (DAT_140009180 == 0) {
      return;
    }
  }
  local_78 = param_5;
  (*(code *)DAT_140009180)(param_1,param_2,param_3,param_4);
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

void FUN_140002cd0(undefined8 param_1)

{
  undefined1 auStack_78 [32];
  ulonglong local_58;
  byte local_48 [48];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_1400091c8 == 0) {
    local_58 = DAT_1400091c8;
    local_48[0x21] = 0;
    local_48[0x22] = 0;
    local_48[0x11] = 0;
    local_48[0x12] = 0;
    local_48[0x13] = 0;
    local_48[0x14] = 0;
    local_48[0x15] = 0;
    local_48[0x16] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0x1b] = 0;
    local_48[0x1c] = 0;
    local_48[0x1d] = 0;
    local_48[0x1e] = 0;
    local_48[0x1f] = 0;
    local_48[0x20] = 0;
    local_48[0] = 0x61;
    local_48[1] = 0x86;
    local_48[2] = 0x5b;
    local_48[3] = 0x8e;
    local_48[4] = 0x51;
    local_48[5] = 0x71;
    local_48[6] = 0x70;
    local_48[7] = 0x8d;
    local_48[8] = 0x71;
    local_48[9] = 0x84;
    local_48[10] = 0x85;
    local_48[0xb] = 0x65;
    local_48[0xc] = 0x79;
    local_48[0xd] = 0x91;
    local_48[0xe] = 0x6f;
    local_48[0xf] = 0x6b;
    local_48[0x10] = 6;
    do {
      local_48[local_58] =
           (char)local_58 + ((char)local_58 + 3U & local_48[local_58]) * -2 + -0x12 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x23);
    DAT_1400091c8 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_1400091c8 == 0) {
      return;
    }
  }
  (*(code *)DAT_1400091c8)(param_1);
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_140002dd0(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_68 [32];
  ulonglong local_48;
  byte local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_68;
  if (DAT_140009170 == 0) {
    local_48 = DAT_140009170;
    local_38[0xf] = 0;
    local_38[0x10] = 0;
    local_38[0x11] = 0;
    local_38[0x12] = 0;
    local_38[0x13] = 0;
    local_38[0x14] = 0;
    local_38[0] = 0xc1;
    local_38[1] = 0xa0;
    local_38[2] = 0x47;
    local_38[3] = 0x61;
    local_38[4] = 0x5d;
    local_38[5] = 0x50;
    local_38[6] = 0x66;
    local_38[7] = 0x3e;
    local_38[8] = 0x67;
    local_38[9] = 0x42;
    local_38[10] = 0x6a;
    local_38[0xb] = 0x5a;
    local_38[0xc] = 0x5f;
    local_38[0xd] = 0x5c;
    local_38[0xe] = 0xfe;
    do {
      local_38[local_48] =
           ('\x06' - ((char)local_48 + 0x7eU & local_38[local_48])) * '\x02' + (char)local_48 +
           local_38[local_48];
      local_48 = local_48 + 1;
    } while (local_48 < 0x15);
    DAT_140009170 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_38);
    if (DAT_140009170 == 0) {
      return;
    }
  }
  (*(code *)DAT_140009170)(param_1,param_2);
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_140002ed0(undefined8 param_1)

{
  undefined1 auStack_78 [32];
  ulonglong local_58;
  byte local_48 [48];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_140009168 == 0) {
    local_58 = DAT_140009168;
    local_48[0x24] = 0;
    local_48[0x25] = 0;
    local_48[0x26] = 0;
    local_48[0x27] = 0;
    local_48[0x28] = 0;
    local_48[0x14] = 0;
    local_48[0x15] = 0;
    local_48[0x16] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0x1b] = 0;
    local_48[0x1c] = 0;
    local_48[0x1d] = 0;
    local_48[0x1e] = 0;
    local_48[0x1f] = 0;
    local_48[0x20] = 0;
    local_48[0x21] = 0;
    local_48[0x22] = 0;
    local_48[0x23] = 0;
    local_48[0] = 0xbf;
    local_48[1] = 0x8b;
    local_48[2] = 0xb6;
    local_48[3] = 0x96;
    local_48[4] = 0x86;
    local_48[5] = 0x94;
    local_48[6] = 0x9c;
    local_48[7] = 0x92;
    local_48[8] = 0x82;
    local_48[9] = 0x90;
    local_48[10] = 0x88;
    local_48[0xb] = 0x9c;
    local_48[0xc] = 0x9d;
    local_48[0xd] = 0xaa;
    local_48[0xe] = 0x98;
    local_48[0xf] = 0x91;
    local_48[0x10] = 0x99;
    local_48[0x11] = 0x9a;
    local_48[0x12] = 0xf6;
    local_48[0x13] = 3;
    do {
      local_48[local_58] =
           (char)local_58 + ((char)local_58 + 0x2eU & local_48[local_58]) * -2 + -0x14 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x29);
    DAT_140009168 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_140009168 == 0) {
      return;
    }
  }
  (*(code *)DAT_140009168)(param_1);
  return;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_140002fc0(undefined8 param_1)

{
  undefined1 auStack_78 [32];
  ulonglong local_58;
  byte local_48 [22];
  ulonglong local_32;
  undefined4 local_2a;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_140009140 == 0) {
    local_58 = DAT_140009140;
    local_32 = DAT_140009140;
    local_2a = 0;
    local_48[0] = 0x7f;
    local_48[1] = 0x4b;
    local_48[2] = 0x7f;
    local_48[3] = 0x42;
    local_48[4] = 0x5f;
    local_48[5] = 0x44;
    local_48[6] = 0x72;
    local_48[7] = 0x42;
    local_48[8] = 0x59;
    local_48[9] = 0x55;
    local_48[10] = 0x49;
    local_48[0xb] = 0x4d;
    local_48[0xc] = 0x59;
    local_48[0xd] = 0x4f;
    local_48[0xe] = 0xb7;
    local_48[0xf] = 0x6c;
    local_48[0x10] = 0x5a;
    local_48[0x11] = 0x43;
    local_48[0x12] = 0x57;
    local_48[0x13] = 0x54;
    local_48[0x14] = 0x44;
    local_48[0x15] = 0x31;
    do {
      local_48[local_58] =
           ('\x0e' - ((char)local_58 + 0x26U & local_48[local_58])) * '\x02' + (char)local_58 +
           local_48[local_58];
      local_58 = local_58 + 1;
    } while (local_58 < 0x22);
    DAT_140009140 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_140009140 == 0) {
      return;
    }
  }
  (*(code *)DAT_140009140)(param_1);
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_1400030b0(void)

{
  undefined1 auStack_68 [32];
  char *local_48;
  byte local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_68;
  if (DAT_1400091b0 == 0) {
    if (DAT_1400091b8 == (char *)0x0) {
      local_48 = DAT_1400091b8;
      local_38[0] = 0x3b;
      local_38[1] = 0x1e;
      local_38[2] = 0x3d;
      local_38[3] = 0x18;
      local_38[4] = 10;
      local_38[5] = 9;
      local_38[6] = 0xb;
      local_38[7] = 0xd;
      local_38[8] = 0x19;
      local_38[9] = 0x21;
      local_38[10] = 0x17;
      local_38[0xb] = 1;
      local_38[0xc] = 7;
      local_38[0xd] = 0xe;
      local_38[0xe] = 1;
      local_38[0xf] = 3;
      local_38[0x10] = 0x11;
      local_38[0x11] = 0xf7;
      local_38[0x12] = 0xfc;
      local_38[0x13] = 0xdf;
      local_38[0x14] = 0xf2;
      local_38[0x15] = 0xff;
      local_38[0x16] = 0xeb;
      local_38[0x17] = 0xec;
      local_38[0x18] = 0xea;
      local_38[0x19] = 0xd4;
      local_38[0x1a] = 0xf4;
      local_38[0x1b] = 0xe0;
      local_38[0x1c] = 0xf6;
      local_38[0x1d] = 0xe2;
      local_38[0x1e] = 0x84;
      local_38[0x1f] = 0;
      do {
        local_38[(longlong)local_48] =
             ('3' - ((char)local_48 - 0x11U & local_38[(longlong)local_48])) * '\x02' +
             (char)local_48 + local_38[(longlong)local_48];
        local_48 = local_48 + 1;
      } while (local_48 < (char *)0x20);
      DAT_1400091b8 = (char *)FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_38);
      if (DAT_1400091b8 == (char *)0x0) {
        return;
      }
    }
    for (; ((*DAT_1400091b8 != ' ' || (DAT_1400091b8[1] != 'H')) || (DAT_1400091b8[2] != -0x73));
        DAT_1400091b8 = DAT_1400091b8 + 1) {
    }
    DAT_1400091b0 = *(longlong *)(DAT_1400091b8 + (longlong)*(int *)(DAT_1400091b8 + 4) + 8);
  }
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

undefined8 FUN_1400031e0(void)

{
  undefined1 auStack_78 [32];
  undefined8 *local_58;
  byte local_48 [48];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_78;
  if (DAT_1400091a0 == (undefined8 *)0x0) {
    local_58 = DAT_1400091a0;
    local_48[0x27] = 0;
    local_48[0x17] = 0;
    local_48[0x18] = 0;
    local_48[0x19] = 0;
    local_48[0x1a] = 0;
    local_48[0x1b] = 0;
    local_48[0x1c] = 0;
    local_48[0x1d] = 0;
    local_48[0x1e] = 0;
    local_48[0x1f] = 0;
    local_48[0x20] = 0;
    local_48[0x21] = 0;
    local_48[0x22] = 0;
    local_48[0x23] = 0;
    local_48[0x24] = 0;
    local_48[0x25] = 0;
    local_48[0x26] = 0;
    local_48[0] = 0x86;
    local_48[1] = 0xec;
    local_48[2] = 0x9b;
    local_48[3] = 0xe5;
    local_48[4] = 0xf9;
    local_48[5] = 0xe1;
    local_48[6] = 0xf7;
    local_48[7] = 0xfc;
    local_48[8] = 0xea;
    local_48[9] = 0x84;
    local_48[10] = 0xe3;
    local_48[0xb] = 0xe6;
    local_48[0xc] = 0xe6;
    local_48[0xd] = 0x8a;
    local_48[0xe] = 0x93;
    local_48[0xf] = 0xf7;
    local_48[0x10] = 0x94;
    local_48[0x11] = 0x90;
    local_48[0x12] = 0x8d;
    local_48[0x13] = 0x8c;
    local_48[0x14] = 0x9f;
    local_48[0x15] = 0x90;
    local_48[0x16] = 0x2c;
    do {
      local_48[(longlong)local_58] =
           (char)local_58 + ((char)local_58 + 0x33U & local_48[(longlong)local_58]) * -2 + -0x32 +
           local_48[(longlong)local_58];
      local_58 = (undefined8 *)((longlong)local_58 + 1);
    } while (local_58 < (undefined8 *)0x28);
    DAT_1400091a0 = (undefined8 *)FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_48);
    if (DAT_1400091a0 == (undefined8 *)0x0) {
      return 0;
    }
  }
  return *DAT_1400091a0;
}



// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall
// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie

void FUN_1400032d0(undefined8 param_1,undefined8 param_2)

{
  undefined1 auStack_68 [32];
  ulonglong local_48;
  byte local_38 [32];
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_68;
  if (DAT_140009160 == 0) {
    local_48 = DAT_140009160;
    local_38[0x1e] = 0;
    local_38[0x1f] = 0;
    local_38[0xe] = 0;
    local_38[0xf] = 0;
    local_38[0x10] = 0;
    local_38[0x11] = 0;
    local_38[0x12] = 0;
    local_38[0x13] = 0;
    local_38[0x14] = 0;
    local_38[0x15] = 0;
    local_38[0x16] = 0;
    local_38[0x17] = 0;
    local_38[0x18] = 0;
    local_38[0x19] = 0;
    local_38[0x1a] = 0;
    local_38[0x1b] = 0;
    local_38[0x1c] = 0;
    local_38[0x1d] = 0;
    local_38[0] = 0x6a;
    local_38[1] = 0x55;
    local_38[2] = 0x4e;
    local_38[3] = 0x71;
    local_38[4] = 0x49;
    local_38[5] = 0x47;
    local_38[6] = 0x41;
    local_38[7] = 0x62;
    local_38[8] = 0x4d;
    local_38[9] = 0x44;
    local_38[10] = 0x45;
    local_38[0xb] = 0x41;
    local_38[0xc] = 0x45;
    local_38[0xd] = 0xcd;
    do {
      local_38[local_48] =
           (char)local_48 + ((char)local_48 + 100U & local_38[local_48]) * -2 + -0x58 +
           local_38[local_48];
      local_48 = local_48 + 1;
    } while (local_48 < 0x20);
    DAT_140009160 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_38);
    if (DAT_140009160 == 0) {
      return;
    }
  }
  (*(code *)DAT_140009160)(param_1,param_2);
  return;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

ulonglong FUN_1400033d0(ulonglong *param_1,ulonglong param_2)

{
  ulonglong *puVar1;
  longlong lVar2;
  undefined8 uVar3;
  ulonglong *puVar4;
  ulonglong uVar5;
  int iVar6;
  ulonglong uVar7;
  ulonglong *puVar8;
  ulonglong uVar9;
  undefined1 auStack_a8 [32];
  ulonglong *local_88;
  byte local_78 [26];
  ulonglong local_5e;
  undefined1 local_56;
  ulonglong *local_48;
  
  puVar1 = (ulonglong *)(DAT_140005000 ^ (ulonglong)auStack_a8);
  if (param_2 == 0) goto LAB_14000358c;
  local_48 = puVar1;
  if (DAT_140009198 == 0) {
    local_88 = (ulonglong *)DAT_140009198;
    local_5e = DAT_140009198;
    local_56 = 0;
    local_78[0] = 1;
    local_78[1] = 0xe6;
    local_78[2] = 0x19;
    local_78[3] = 0xfc;
    local_78[4] = 0xee;
    local_78[5] = 0xd;
    local_78[6] = 0xf4;
    local_78[7] = 0xe4;
    local_78[8] = 0xe3;
    local_78[9] = 0xf2;
    local_78[10] = 0xf5;
    local_78[0xb] = 0xf8;
    local_78[0xc] = 0xee;
    local_78[0xd] = 0xf2;
    local_78[0xe] = 0xb;
    local_78[0xf] = 0x10;
    local_78[0x10] = 0x17;
    local_78[0x11] = 0x13;
    local_78[0x12] = 0x1b;
    local_78[0x13] = 0xf1;
    local_78[0x14] = 1;
    local_78[0x15] = 0x1b;
    local_78[0x16] = 5;
    local_78[0x17] = 0;
    local_78[0x18] = 0x13;
    local_78[0x19] = 0xa9;
    do {
      local_78[(longlong)local_88] =
           ('\'' - ((char)local_88 - 0xdU & local_78[(longlong)local_88])) * '\x02' + (char)local_88
           + local_78[(longlong)local_88];
      local_88 = (ulonglong *)((longlong)local_88 + 1);
    } while (local_88 < 0x23);
    DAT_140009198 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_78);
    if (DAT_140009198 != 0) goto LAB_1400034b2;
    puVar1 = (ulonglong *)0x0;
  }
  else {
LAB_1400034b2:
    puVar1 = (ulonglong *)(*(code *)DAT_140009198)();
  }
  uVar7 = *puVar1;
  uVar9 = puVar1[1];
  if (uVar7 != 0) {
    puVar4 = puVar1;
    puVar8 = (ulonglong *)0x0;
    local_88 = puVar1;
    do {
      puVar1 = puVar8;
      if (uVar9 == 0) break;
      iVar6 = 0;
      if (0 < (longlong)uVar9) {
        do {
          uVar5 = uVar7 & 0xfffffffff000;
          if (uVar5 != 0) {
            lVar2 = param_1[1] + (uVar5 >> 0xc) * 0x30;
            if (((lVar2 != 0) && ((*(ulonglong *)(lVar2 + 0x28) & 0xffffffffff) == uVar5 >> 0xc)) &&
               (uVar3 = FUN_140001770((longlong)param_1,uVar7,param_2), (char)uVar3 != '\0')) {
              *param_1 = uVar5;
              return CONCAT71((int7)((ulonglong)uVar3 >> 8),1);
            }
          }
          iVar6 = iVar6 + 0x1000;
          uVar7 = uVar7 + 0x1000;
          puVar4 = local_88;
        } while ((longlong)iVar6 < (longlong)uVar9);
      }
      puVar8 = (ulonglong *)((longlong)puVar1 + 1);
      lVar2 = (longlong)puVar1 + 1;
      puVar1 = (ulonglong *)(lVar2 * 2);
      uVar7 = puVar4[lVar2 * 2];
      uVar9 = puVar4[lVar2 * 2 + 1];
    } while (uVar7 != 0);
  }
LAB_14000358c:
  return (ulonglong)puVar1 & 0xffffffffffffff00;
}



// WARNING: Type propagation algorithm not settling

longlong FUN_1400035c0(longlong *param_1,ulonglong param_2,undefined4 *param_3)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  ulonglong local_res8;
  ulonglong local_res20;
  ulonglong local_28 [2];
  
  if (((*param_1 != 0) &&
      (uVar2 = (ulonglong)((uint)(param_2 >> 0x27) & 0x1ff), uVar2 < (ulonglong)param_1[0x202])) &&
     ((param_1[uVar2 + 2] & 1U) != 0)) {
    local_res8 = 0;
    local_28[1] = 0;
    iVar1 = FUN_140002bb0(&local_res8,
                          (param_1[uVar2 + 2] & 0xfffffffff000U) +
                          (ulonglong)((uint)(param_2 >> 0x1e) & 0x1ff) * 8,8,1,local_28 + 1);
    if ((iVar1 == 0) && ((local_res8 & 1) != 0)) {
      uVar4 = (uint)param_2;
      if ((char)local_res8 < '\0') {
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = 0x40000000;
        }
        return (local_res8 & 0xfffffffff000) + (ulonglong)(uVar4 & 0x3fffffff);
      }
      local_res20 = 0;
      local_28[1] = 0;
      iVar1 = FUN_140002bb0(&local_res20,
                            (local_res8 & 0xfffffffff000) +
                            (ulonglong)((uint)(param_2 >> 0x15) & 0x1ff) * 8,8,1,local_28 + 1);
      if ((iVar1 == 0) && ((local_res20 & 1) != 0)) {
        if ((char)local_res20 < '\0') {
          if (param_3 != (undefined4 *)0x0) {
            *param_3 = 0x200000;
          }
          return (local_res20 & 0xfffffffff000) + (ulonglong)(uVar4 & 0x1fffff);
        }
        local_28[0] = 0;
        local_28[1] = 0;
        iVar1 = FUN_140002bb0(local_28,(local_res20 & 0xfffffffff000) +
                                       (ulonglong)((uint)(param_2 >> 0xc) & 0x1ff) * 8,8,1,
                              local_28 + 1);
        if ((iVar1 == 0) && ((local_28[0] & 1) != 0)) {
          lVar3 = (local_28[0] & 0xfffffffff000) + (ulonglong)(uVar4 & 0xfff);
          if (param_3 == (undefined4 *)0x0) {
            return lVar3;
          }
          *param_3 = 0x1000;
          return lVar3;
        }
      }
    }
  }
  return 0;
}



void FUN_140003790(longlong param_1)

{
  FUN_140002880(&DAT_1400050a0);
  if (*(longlong *)(param_1 + 8) != 0) {
    FUN_140002770(*(longlong *)(param_1 + 8));
    return;
  }
  return;
}



undefined4 FUN_1400037c0(undefined8 param_1,longlong param_2)

{
  *(undefined4 *)(param_2 + 0x30) = 0xc00000bb;
  FUN_140002980(param_2,0);
  return *(undefined4 *)(param_2 + 0x30);
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// WARNING: Function: _guard_dispatch_icall replaced with injection: guard_dispatch_icall

undefined8 FUN_1400037f0(undefined8 param_1,longlong param_2,longlong param_3)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  byte bVar3;
  undefined1 auStack_68 [32];
  undefined1 *local_48;
  longlong local_40;
  byte local_38 [15];
  ulonglong local_29;
  undefined4 local_21;
  ulonglong local_18;
  
  local_18 = DAT_140005000 ^ (ulonglong)auStack_68;
  local_40 = param_3;
  if (DAT_140009178 == 0) {
    local_38[0] = 0x61;
    local_38[1] = 0x46;
    local_38[2] = 0x67;
    local_38[3] = 0x70;
    local_38[4] = 0x42;
    local_38[5] = 0x16;
    local_38[6] = 0x4d;
    local_38[7] = 0x62;
    local_38[8] = 0x4e;
    local_38[9] = 0x7a;
    local_38[10] = 0x75;
    local_38[0xb] = 0x74;
    local_38[0xc] = 0x15;
    local_38[0xd] = 0x5d;
    local_38[0xe] = 0xc4;
    local_29 = DAT_140009178;
    local_21 = 0;
    local_48 = (undefined1 *)DAT_140009178;
    do {
      bVar3 = (char)local_48 + 0xa3;
      local_38[(longlong)local_48] =
           local_38[(longlong)local_48] + (local_38[(longlong)local_48] & bVar3) * -2 + -0x75 +
           bVar3;
      local_48 = (undefined1 *)((longlong)local_48 + 1);
    } while (local_48 < 0x1b);
    DAT_140009178 = FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_38);
    if (DAT_140009178 != 0) goto LAB_1400038d2;
    puVar1 = (undefined1 *)0x0;
  }
  else {
LAB_1400038d2:
    puVar1 = (undefined1 *)(*(code *)DAT_140009178)(param_1,param_3,4);
  }
  if (puVar1 == (undefined1 *)0x0) {
    return 0;
  }
  local_48 = puVar1;
  FUN_140002b80(puVar1,param_2,param_3);
  if (DAT_140009170 == (undefined1 *)0x0) {
    local_38[0] = 0xc1;
    local_38[1] = 0xa0;
    local_38[2] = 0x47;
    local_38[3] = 0x61;
    local_38[4] = 0x5d;
    local_38[5] = 0x50;
    local_38[6] = 0x66;
    local_38[7] = 0x3e;
    local_38[8] = 0x67;
    local_38[9] = 0x42;
    local_38[10] = 0x6a;
    local_38[0xb] = 0x5a;
    local_38[0xc] = 0x5f;
    local_38[0xd] = 0x5c;
    local_38[0xe] = 0xfe;
    local_29 = local_29 & 0xffff000000000000;
    local_48 = DAT_140009170;
    do {
      bVar3 = (char)local_48 + 0x7e;
      local_38[(longlong)local_48] =
           local_38[(longlong)local_48] + (local_38[(longlong)local_48] & bVar3) * -2 + -0x72 +
           bVar3;
      local_48 = local_48 + 1;
    } while (local_48 < (undefined1 *)0x15);
    DAT_140009170 = (undefined1 *)FUN_140002180((undefined8 *)&DAT_140005080,(char *)local_38);
    uVar2 = 0;
    if (DAT_140009170 == (undefined1 *)0x0) goto LAB_1400039dd;
  }
  uVar2 = (*(code *)DAT_140009170)(puVar1,param_3);
LAB_1400039dd:
  return CONCAT71((int7)((ulonglong)uVar2 >> 8),1);
}



void FUN_1400039f0(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x29);
  (*pcVar1)(2);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}



void _guard_check_icall(void)

{
  return;
}



void DbgPrint(void)

{
                    // WARNING: Could not recover jumptable at 0x000140003a10. Too many branches
                    // WARNING: Treating indirect jump as call
  DbgPrint();
  return;
}



void ObCreateObject(void)

{
                    // WARNING: Could not recover jumptable at 0x000140003a16. Too many branches
                    // WARNING: Treating indirect jump as call
  ObCreateObject();
  return;
}



// WARNING: Unknown calling convention -- yet parameter storage is locked

EXCEPTION_DISPOSITION
__C_specific_handler
          (_EXCEPTION_RECORD *ExceptionRecord,void *EstablisherFrame,_CONTEXT *ContextRecord,
          _DISPATCHER_CONTEXT *DispatcherContext)

{
  EXCEPTION_DISPOSITION EVar1;
  
                    // WARNING: Could not recover jumptable at 0x000140003a1c. Too many branches
                    // WARNING: Treating indirect jump as call
  EVar1 = __C_specific_handler(ExceptionRecord,EstablisherFrame,ContextRecord,DispatcherContext);
  return EVar1;
}



// Library Function - Single Match
//  __GSHandlerCheck
// 
// Library: Visual Studio 2019 Release

undefined8
__GSHandlerCheck(undefined8 param_1,undefined8 param_2,undefined8 param_3,longlong param_4)

{
  __GSHandlerCheckCommon(param_2,param_4);
  return 1;
}



// WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie
// Library Function - Single Match
//  __GSHandlerCheckCommon
// 
// Library: Visual Studio 2019 Release

ulonglong __GSHandlerCheckCommon(undefined8 param_1,longlong param_2)

{
  byte bVar1;
  ulonglong uVar2;
  
  uVar2 = *(ulonglong *)(param_2 + 8);
  bVar1 = *(byte *)((ulonglong)*(uint *)(*(longlong *)(param_2 + 0x10) + 8) + 3 + uVar2);
  if ((bVar1 & 0xf) != 0) {
    uVar2 = (ulonglong)(bVar1 & 0xfffffff0);
  }
  return uVar2;
}



// Library Function - Single Match
//  __GSHandlerCheck_SEH
// 
// Library: Visual Studio 2019 Release

void __GSHandlerCheck_SEH
               (_EXCEPTION_RECORD *param_1,void *param_2,_CONTEXT *param_3,
               _DISPATCHER_CONTEXT *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = *(uint **)(param_4 + 0x38);
  uVar1 = *puVar2;
  __GSHandlerCheckCommon(param_2,(longlong)param_4);
  if ((puVar2[(ulonglong)uVar1 * 4 + 1] & ((param_1->ExceptionFlags & 0x66) != 0) + 1) != 0) {
    __C_specific_handler(param_1,param_2,param_3,param_4);
  }
  return;
}



// WARNING: This is an inlined function
// WARNING: Function: __chkstk replaced with injection: alloca_probe

void __chkstk(void)

{
                    // WARNING: Could not recover jumptable at 0x000140003b2a. Too many branches
                    // WARNING: Treating indirect jump as call
  return;
}



// WARNING: Removing unreachable block (ram,0x000140003b9a)
// WARNING: Removing unreachable block (ram,0x000140003b49)
// WARNING: Removing unreachable block (ram,0x000140003b3a)

undefined8 FUN_140003b30(void)

{
  int *piVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 uVar4;
  bool bVar5;
  byte bVar6;
  byte bVar7;
  byte in_XCR0;
  
  piVar1 = (int *)cpuid_basic_info(0);
  bVar7 = 0;
  bVar5 = false;
  lVar2 = cpuid_Version_info(1);
  uVar3 = *(uint *)(lVar2 + 0xc);
  if ((uVar3 >> 0x14 & 1) != 0) {
    bVar7 = 8;
    bVar5 = false;
    if (((uVar3 >> 0x1b & 1) != 0) && ((uVar3 >> 0x1c & 1) != 0)) {
      uVar4 = xinuse(0);
      bVar7 = 8;
      bVar5 = false;
      if ((in_XCR0 & (byte)uVar4 & 6) == 6) {
        bVar7 = 0xc;
        bVar5 = true;
      }
    }
  }
  bVar6 = bVar7;
  if (6 < *piVar1) {
    lVar2 = cpuid_Extended_Feature_Enumeration_info(7);
    bVar6 = bVar7 | 2;
    if ((*(uint *)(lVar2 + 4) >> 9 & 1) == 0) {
      bVar6 = bVar7;
    }
    if (((*(uint *)(lVar2 + 4) & 0x20) != 0) && (bVar5)) {
      bVar6 = bVar6 | 0x10;
    }
  }
  DAT_140005040 = bVar6 | 1;
  return 0;
}



// WARNING: This is an inlined function

void __cdecl __security_check_cookie(uintptr_t _StackCookie)

{
  if ((_StackCookie == DAT_140005000) && ((short)(_StackCookie >> 0x30) == 0)) {
    return;
  }
  FUN_1400039f0();
  return;
}



// WARNING: This is an inlined function

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    // WARNING: Could not recover jumptable at 0x000140003c30. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



// WARNING: This is an inlined function

void _guard_dispatch_icall(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
                    // WARNING: Could not recover jumptable at 0x000140003c30. Too many branches
                    // WARNING: Treating indirect jump as call
  (*UNRECOVERED_JUMPTABLE)();
  return;
}



longlong * FUN_140003c80(longlong *param_1,byte param_2,undefined1 *param_3)

{
  longlong *plVar1;
  longlong *plVar2;
  undefined4 uVar3;
  longlong lVar4;
  undefined1 *puVar5;
  ulonglong uVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong extraout_XMM0_Qa;
  longlong extraout_XMM0_Qb;
  
  plVar1 = param_1;
  lVar4 = (ulonglong)param_2 * 0x101010101010101;
  if (param_3 < (undefined1 *)0x40) {
    if (param_3 < (undefined1 *)0x10) {
      if ((undefined1 *)0x3 < param_3) {
        uVar3 = (undefined4)lVar4;
        *(undefined4 *)param_1 = uVar3;
        uVar6 = ((ulonglong)param_3 & 8) >> 1;
        *(undefined4 *)(param_3 + -4 + (longlong)param_1) = uVar3;
        *(undefined4 *)((longlong)param_1 + uVar6) = uVar3;
        *(undefined4 *)((longlong)(param_3 + -4 + (longlong)param_1) - uVar6) = uVar3;
        return plVar1;
      }
      if (param_3 != (undefined1 *)0x0) {
        *(char *)param_1 = (char)lVar4;
        if (param_3 != (undefined1 *)0x1) {
          *(short *)(param_3 + (longlong)param_1 + -2) = (short)lVar4;
        }
      }
      return plVar1;
    }
  }
  else {
    if (((DAT_140005040 & 2) != 0) && ((undefined1 *)0x31f < param_3)) {
      lVar7 = lVar4;
      if ((DAT_140005040 & 1) == 0) {
        param_1 = (longlong *)FUN_140003e40();
        lVar4 = extraout_XMM0_Qa;
        lVar7 = extraout_XMM0_Qb;
      }
      *plVar1 = lVar4;
      plVar1[1] = lVar7;
      plVar1[2] = lVar4;
      plVar1[3] = lVar7;
      plVar1[4] = lVar4;
      plVar1[5] = lVar7;
      plVar1[6] = lVar4;
      plVar1[7] = lVar7;
      puVar5 = (undefined1 *)((ulonglong)(plVar1 + 8) & 0xffffffffffffffc0);
      for (lVar7 = (longlong)(param_3 + (longlong)plVar1) -
                   (longlong)((ulonglong)(plVar1 + 8) & 0xffffffffffffffc0); lVar7 != 0;
          lVar7 = lVar7 + -1) {
        *puVar5 = (char)lVar4;
        puVar5 = puVar5 + 1;
      }
      return param_1;
    }
    *param_1 = lVar4;
    param_1[1] = lVar4;
    puVar5 = param_3 + (longlong)param_1;
    param_1 = (longlong *)((ulonglong)(param_1 + 2) & 0xfffffffffffffff0);
    param_3 = puVar5 + -(longlong)param_1;
    if ((undefined1 *)0x3f < param_3) {
      plVar8 = (longlong *)
               ((ulonglong)((longlong)(param_1 + -6) + (longlong)param_3) & 0xfffffffffffffff0);
      uVar6 = (ulonglong)param_3 >> 6;
      plVar2 = param_1;
      do {
        *plVar2 = lVar4;
        plVar2[1] = lVar4;
        plVar2[2] = lVar4;
        plVar2[3] = lVar4;
        uVar6 = uVar6 - 1;
        plVar2[4] = lVar4;
        plVar2[5] = lVar4;
        plVar2[6] = lVar4;
        plVar2[7] = lVar4;
        plVar2 = plVar2 + 8;
      } while (uVar6 != 0);
      *plVar8 = lVar4;
      plVar8[1] = lVar4;
      plVar8[2] = lVar4;
      plVar8[3] = lVar4;
      plVar8[4] = lVar4;
      plVar8[5] = lVar4;
      *(longlong *)((longlong)(param_1 + -2) + (longlong)param_3) = lVar4;
      ((longlong *)((longlong)(param_1 + -2) + (longlong)param_3))[1] = lVar4;
      return plVar1;
    }
  }
  plVar8 = (longlong *)(param_3 + -0x10 + (longlong)param_1);
  *param_1 = lVar4;
  param_1[1] = lVar4;
  uVar6 = ((ulonglong)param_3 & 0x20) >> 1;
  *plVar8 = lVar4;
  plVar8[1] = lVar4;
  plVar2 = (longlong *)((longlong)param_1 + uVar6);
  *plVar2 = lVar4;
  plVar2[1] = lVar4;
  plVar8 = (longlong *)((longlong)plVar8 - uVar6);
  *plVar8 = lVar4;
  plVar8[1] = lVar4;
  return plVar1;
}



undefined8 FUN_140003dc0(undefined1 *param_1,undefined8 param_2,longlong param_3)

{
  undefined8 in_RAX;
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 in_XMM0_Ba;
  undefined1 extraout_XMM0_Ba;
  undefined1 in_XMM0_Bb;
  undefined1 extraout_XMM0_Bb;
  undefined1 in_XMM0_Bc;
  undefined1 extraout_XMM0_Bc;
  undefined1 in_XMM0_Bd;
  undefined1 extraout_XMM0_Bd;
  undefined1 in_XMM0_Be;
  undefined1 extraout_XMM0_Be;
  undefined1 in_XMM0_Bf;
  undefined1 extraout_XMM0_Bf;
  undefined1 in_XMM0_Bg;
  undefined1 extraout_XMM0_Bg;
  undefined1 in_XMM0_Bh;
  undefined1 extraout_XMM0_Bh;
  undefined1 in_XMM0_Bi;
  undefined1 extraout_XMM0_Bi;
  undefined1 in_XMM0_Bj;
  undefined1 extraout_XMM0_Bj;
  undefined1 in_XMM0_Bk;
  undefined1 extraout_XMM0_Bk;
  undefined1 in_XMM0_Bl;
  undefined1 extraout_XMM0_Bl;
  undefined1 in_XMM0_Bm;
  undefined1 extraout_XMM0_Bm;
  undefined1 in_XMM0_Bn;
  undefined1 extraout_XMM0_Bn;
  undefined1 in_XMM0_Bo;
  undefined1 extraout_XMM0_Bo;
  undefined1 in_XMM0_Bp;
  undefined1 extraout_XMM0_Bp;
  
  if ((DAT_140005040 & 1) == 0) {
    in_RAX = FUN_140003e40();
    in_XMM0_Ba = extraout_XMM0_Ba;
    in_XMM0_Bb = extraout_XMM0_Bb;
    in_XMM0_Bc = extraout_XMM0_Bc;
    in_XMM0_Bd = extraout_XMM0_Bd;
    in_XMM0_Be = extraout_XMM0_Be;
    in_XMM0_Bf = extraout_XMM0_Bf;
    in_XMM0_Bg = extraout_XMM0_Bg;
    in_XMM0_Bh = extraout_XMM0_Bh;
    in_XMM0_Bi = extraout_XMM0_Bi;
    in_XMM0_Bj = extraout_XMM0_Bj;
    in_XMM0_Bk = extraout_XMM0_Bk;
    in_XMM0_Bl = extraout_XMM0_Bl;
    in_XMM0_Bm = extraout_XMM0_Bm;
    in_XMM0_Bn = extraout_XMM0_Bn;
    in_XMM0_Bo = extraout_XMM0_Bo;
    in_XMM0_Bp = extraout_XMM0_Bp;
  }
  *param_1 = in_XMM0_Ba;
  param_1[1] = in_XMM0_Bb;
  param_1[2] = in_XMM0_Bc;
  param_1[3] = in_XMM0_Bd;
  param_1[4] = in_XMM0_Be;
  param_1[5] = in_XMM0_Bf;
  param_1[6] = in_XMM0_Bg;
  param_1[7] = in_XMM0_Bh;
  param_1[8] = in_XMM0_Bi;
  param_1[9] = in_XMM0_Bj;
  param_1[10] = in_XMM0_Bk;
  param_1[0xb] = in_XMM0_Bl;
  param_1[0xc] = in_XMM0_Bm;
  param_1[0xd] = in_XMM0_Bn;
  param_1[0xe] = in_XMM0_Bo;
  param_1[0xf] = in_XMM0_Bp;
  param_1[0x10] = in_XMM0_Ba;
  param_1[0x11] = in_XMM0_Bb;
  param_1[0x12] = in_XMM0_Bc;
  param_1[0x13] = in_XMM0_Bd;
  param_1[0x14] = in_XMM0_Be;
  param_1[0x15] = in_XMM0_Bf;
  param_1[0x16] = in_XMM0_Bg;
  param_1[0x17] = in_XMM0_Bh;
  param_1[0x18] = in_XMM0_Bi;
  param_1[0x19] = in_XMM0_Bj;
  param_1[0x1a] = in_XMM0_Bk;
  param_1[0x1b] = in_XMM0_Bl;
  param_1[0x1c] = in_XMM0_Bm;
  param_1[0x1d] = in_XMM0_Bn;
  param_1[0x1e] = in_XMM0_Bo;
  param_1[0x1f] = in_XMM0_Bp;
  param_1[0x20] = in_XMM0_Ba;
  param_1[0x21] = in_XMM0_Bb;
  param_1[0x22] = in_XMM0_Bc;
  param_1[0x23] = in_XMM0_Bd;
  param_1[0x24] = in_XMM0_Be;
  param_1[0x25] = in_XMM0_Bf;
  param_1[0x26] = in_XMM0_Bg;
  param_1[0x27] = in_XMM0_Bh;
  param_1[0x28] = in_XMM0_Bi;
  param_1[0x29] = in_XMM0_Bj;
  param_1[0x2a] = in_XMM0_Bk;
  param_1[0x2b] = in_XMM0_Bl;
  param_1[0x2c] = in_XMM0_Bm;
  param_1[0x2d] = in_XMM0_Bn;
  param_1[0x2e] = in_XMM0_Bo;
  param_1[0x2f] = in_XMM0_Bp;
  param_1[0x30] = in_XMM0_Ba;
  param_1[0x31] = in_XMM0_Bb;
  param_1[0x32] = in_XMM0_Bc;
  param_1[0x33] = in_XMM0_Bd;
  param_1[0x34] = in_XMM0_Be;
  param_1[0x35] = in_XMM0_Bf;
  param_1[0x36] = in_XMM0_Bg;
  param_1[0x37] = in_XMM0_Bh;
  param_1[0x38] = in_XMM0_Bi;
  param_1[0x39] = in_XMM0_Bj;
  param_1[0x3a] = in_XMM0_Bk;
  param_1[0x3b] = in_XMM0_Bl;
  param_1[0x3c] = in_XMM0_Bm;
  param_1[0x3d] = in_XMM0_Bn;
  param_1[0x3e] = in_XMM0_Bo;
  param_1[0x3f] = in_XMM0_Bp;
  puVar1 = (undefined1 *)((ulonglong)(param_1 + 0x40) & 0xffffffffffffffc0);
  for (puVar2 = param_1 + (param_3 - (longlong)((ulonglong)(param_1 + 0x40) & 0xffffffffffffffc0));
      puVar2 != (undefined1 *)0x0; puVar2 = puVar2 + -1) {
    *puVar1 = in_XMM0_Ba;
    puVar1 = puVar1 + 1;
  }
  return in_RAX;
}



undefined8 FUN_140003e40(void)

{
  undefined8 in_RAX;
  
  FUN_140003b30();
  return in_RAX;
}



void FUN_140003f10(undefined8 param_1,longlong param_2)

{
  FUN_140002dd0(*(undefined8 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x28));
  return;
}


