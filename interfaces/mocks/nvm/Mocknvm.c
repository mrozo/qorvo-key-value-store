/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "Mocknvm.h"

static const char* CMockString_address = "address";
static const char* CMockString_data = "data";
static const char* CMockString_desc = "desc";
static const char* CMockString_nvmDeinit = "nvmDeinit";
static const char* CMockString_nvmEraseAll = "nvmEraseAll";
static const char* CMockString_nvmErasePages = "nvmErasePages";
static const char* CMockString_nvmGetInfo = "nvmGetInfo";
static const char* CMockString_nvmInit = "nvmInit";
static const char* CMockString_nvmInstance = "nvmInstance";
static const char* CMockString_nvmRead = "nvmRead";
static const char* CMockString_nvmWirte = "nvmWirte";
static const char* CMockString_pageNumber = "pageNumber";
static const char* CMockString_pagesCount = "pagesCount";
static const char* CMockString_size = "size";

typedef struct _CMOCK_nvmInit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  enum nvmStatus ReturnVal;
  struct nvmInstance** Expected_nvmInstance;
  struct nvmDescription Expected_desc;

} CMOCK_nvmInit_CALL_INSTANCE;

typedef struct _CMOCK_nvmWirte_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  enum nvmStatus ReturnVal;
  struct nvmInstance* Expected_nvmInstance;
  size_t Expected_address;
  size_t Expected_size;
  const uint8_t* Expected_data;

} CMOCK_nvmWirte_CALL_INSTANCE;

typedef struct _CMOCK_nvmRead_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  enum nvmStatus ReturnVal;
  struct nvmInstance* Expected_nvmInstance;
  size_t Expected_address;
  size_t Expected_size;
  uint8_t* Expected_data;

} CMOCK_nvmRead_CALL_INSTANCE;

typedef struct _CMOCK_nvmErasePages_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  enum nvmStatus ReturnVal;
  struct nvmInstance* Expected_nvmInstance;
  size_t Expected_pageNumber;
  size_t Expected_pagesCount;

} CMOCK_nvmErasePages_CALL_INSTANCE;

typedef struct _CMOCK_nvmDeinit_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  enum nvmStatus ReturnVal;
  struct nvmInstance** Expected_nvmInstance;

} CMOCK_nvmDeinit_CALL_INSTANCE;

typedef struct _CMOCK_nvmEraseAll_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  enum nvmStatus ReturnVal;
  struct nvmInstance* Expected_nvmInstance;

} CMOCK_nvmEraseAll_CALL_INSTANCE;

typedef struct _CMOCK_nvmGetInfo_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  char ExpectAnyArgsBool;
  struct nvmDescription ReturnVal;
  struct nvmInstance* Expected_nvmInstance;

} CMOCK_nvmGetInfo_CALL_INSTANCE;

static struct MocknvmInstance
{
  char nvmInit_CallbackBool;
  CMOCK_nvmInit_CALLBACK nvmInit_CallbackFunctionPointer;
  int nvmInit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nvmInit_CallInstance;
  char nvmWirte_CallbackBool;
  CMOCK_nvmWirte_CALLBACK nvmWirte_CallbackFunctionPointer;
  int nvmWirte_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nvmWirte_CallInstance;
  char nvmRead_CallbackBool;
  CMOCK_nvmRead_CALLBACK nvmRead_CallbackFunctionPointer;
  int nvmRead_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nvmRead_CallInstance;
  char nvmErasePages_CallbackBool;
  CMOCK_nvmErasePages_CALLBACK nvmErasePages_CallbackFunctionPointer;
  int nvmErasePages_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nvmErasePages_CallInstance;
  char nvmDeinit_CallbackBool;
  CMOCK_nvmDeinit_CALLBACK nvmDeinit_CallbackFunctionPointer;
  int nvmDeinit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nvmDeinit_CallInstance;
  char nvmEraseAll_CallbackBool;
  CMOCK_nvmEraseAll_CALLBACK nvmEraseAll_CallbackFunctionPointer;
  int nvmEraseAll_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nvmEraseAll_CallInstance;
  char nvmGetInfo_CallbackBool;
  CMOCK_nvmGetInfo_CALLBACK nvmGetInfo_CallbackFunctionPointer;
  int nvmGetInfo_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE nvmGetInfo_CallInstance;
} Mock;

extern jmp_buf AbortFrame;

void Mocknvm_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.nvmInit_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_nvmInit);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.nvmInit_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.nvmWirte_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_nvmWirte);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.nvmWirte_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.nvmRead_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_nvmRead);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.nvmRead_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.nvmErasePages_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_nvmErasePages);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.nvmErasePages_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.nvmDeinit_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_nvmDeinit);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.nvmDeinit_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.nvmEraseAll_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_nvmEraseAll);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.nvmEraseAll_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.nvmGetInfo_CallInstance;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_nvmGetInfo);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.nvmGetInfo_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void Mocknvm_Init(void)
{
  Mocknvm_Destroy();
}

void Mocknvm_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
}

enum nvmStatus nvmInit(struct nvmInstance** nvmInstance, struct nvmDescription desc)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nvmInit_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_nvmInit);
  cmock_call_instance = (CMOCK_nvmInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nvmInit_CallInstance);
  Mock.nvmInit_CallInstance = CMock_Guts_MemNext(Mock.nvmInit_CallInstance);
  if (!Mock.nvmInit_CallbackBool &&
      Mock.nvmInit_CallbackFunctionPointer != NULL)
  {
    enum nvmStatus cmock_cb_ret = Mock.nvmInit_CallbackFunctionPointer(nvmInstance, desc, Mock.nvmInit_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  {
    UNITY_SET_DETAILS(CMockString_nvmInit,CMockString_nvmInstance);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_nvmInstance, nvmInstance, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmInit,CMockString_desc);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_desc), (void*)(&desc), sizeof(struct nvmDescription), cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.nvmInit_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.nvmInit_CallbackFunctionPointer(nvmInstance, desc, Mock.nvmInit_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nvmInit(CMOCK_nvmInit_CALL_INSTANCE* cmock_call_instance, struct nvmInstance** nvmInstance, struct nvmDescription desc);
void CMockExpectParameters_nvmInit(CMOCK_nvmInit_CALL_INSTANCE* cmock_call_instance, struct nvmInstance** nvmInstance, struct nvmDescription desc)
{
  cmock_call_instance->Expected_nvmInstance = nvmInstance;
  memcpy((void*)(&cmock_call_instance->Expected_desc), (void*)(&desc),
         sizeof(struct nvmDescription[sizeof(desc) == sizeof(struct nvmDescription) ? 1 : -1])); /* add struct nvmDescription to :treat_as_array if this causes an error */
}

void nvmInit_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmInit_CALL_INSTANCE));
  CMOCK_nvmInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmInit_CallInstance = CMock_Guts_MemChain(Mock.nvmInit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void nvmInit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmInstance** nvmInstance, struct nvmDescription desc, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmInit_CALL_INSTANCE));
  CMOCK_nvmInit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmInit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmInit_CallInstance = CMock_Guts_MemChain(Mock.nvmInit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_nvmInit(cmock_call_instance, nvmInstance, desc);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(enum nvmStatus[sizeof(cmock_to_return) == sizeof(enum nvmStatus) ? 1 : -1])); /* add enum nvmStatus to :treat_as_array if this causes an error */
}

void nvmInit_AddCallback(CMOCK_nvmInit_CALLBACK Callback)
{
  Mock.nvmInit_CallbackBool = (char)1;
  Mock.nvmInit_CallbackFunctionPointer = Callback;
}

void nvmInit_Stub(CMOCK_nvmInit_CALLBACK Callback)
{
  Mock.nvmInit_CallbackBool = (char)0;
  Mock.nvmInit_CallbackFunctionPointer = Callback;
}

enum nvmStatus nvmWirte(struct nvmInstance* nvmInstance, size_t address, size_t size, const uint8_t* data)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nvmWirte_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_nvmWirte);
  cmock_call_instance = (CMOCK_nvmWirte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nvmWirte_CallInstance);
  Mock.nvmWirte_CallInstance = CMock_Guts_MemNext(Mock.nvmWirte_CallInstance);
  if (!Mock.nvmWirte_CallbackBool &&
      Mock.nvmWirte_CallbackFunctionPointer != NULL)
  {
    enum nvmStatus cmock_cb_ret = Mock.nvmWirte_CallbackFunctionPointer(nvmInstance, address, size, data, Mock.nvmWirte_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  {
    UNITY_SET_DETAILS(CMockString_nvmWirte,CMockString_nvmInstance);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_nvmInstance, nvmInstance, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmWirte,CMockString_address);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_address), (void*)(&address), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmWirte,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_size), (void*)(&size), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmWirte,CMockString_data);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_data, data, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.nvmWirte_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.nvmWirte_CallbackFunctionPointer(nvmInstance, address, size, data, Mock.nvmWirte_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nvmWirte(CMOCK_nvmWirte_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance, size_t address, size_t size, const uint8_t* data);
void CMockExpectParameters_nvmWirte(CMOCK_nvmWirte_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance, size_t address, size_t size, const uint8_t* data)
{
  cmock_call_instance->Expected_nvmInstance = nvmInstance;
  memcpy((void*)(&cmock_call_instance->Expected_address), (void*)(&address),
         sizeof(size_t[sizeof(address) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_size), (void*)(&size),
         sizeof(size_t[sizeof(size) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  cmock_call_instance->Expected_data = data;
}

void nvmWirte_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmWirte_CALL_INSTANCE));
  CMOCK_nvmWirte_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmWirte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmWirte_CallInstance = CMock_Guts_MemChain(Mock.nvmWirte_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void nvmWirte_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmInstance* nvmInstance, size_t address, size_t size, const uint8_t* data, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmWirte_CALL_INSTANCE));
  CMOCK_nvmWirte_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmWirte_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmWirte_CallInstance = CMock_Guts_MemChain(Mock.nvmWirte_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_nvmWirte(cmock_call_instance, nvmInstance, address, size, data);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(enum nvmStatus[sizeof(cmock_to_return) == sizeof(enum nvmStatus) ? 1 : -1])); /* add enum nvmStatus to :treat_as_array if this causes an error */
}

void nvmWirte_AddCallback(CMOCK_nvmWirte_CALLBACK Callback)
{
  Mock.nvmWirte_CallbackBool = (char)1;
  Mock.nvmWirte_CallbackFunctionPointer = Callback;
}

void nvmWirte_Stub(CMOCK_nvmWirte_CALLBACK Callback)
{
  Mock.nvmWirte_CallbackBool = (char)0;
  Mock.nvmWirte_CallbackFunctionPointer = Callback;
}

enum nvmStatus nvmRead(struct nvmInstance* nvmInstance, size_t address, size_t size, uint8_t* data)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nvmRead_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_nvmRead);
  cmock_call_instance = (CMOCK_nvmRead_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nvmRead_CallInstance);
  Mock.nvmRead_CallInstance = CMock_Guts_MemNext(Mock.nvmRead_CallInstance);
  if (!Mock.nvmRead_CallbackBool &&
      Mock.nvmRead_CallbackFunctionPointer != NULL)
  {
    enum nvmStatus cmock_cb_ret = Mock.nvmRead_CallbackFunctionPointer(nvmInstance, address, size, data, Mock.nvmRead_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  {
    UNITY_SET_DETAILS(CMockString_nvmRead,CMockString_nvmInstance);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_nvmInstance, nvmInstance, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmRead,CMockString_address);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_address), (void*)(&address), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmRead,CMockString_size);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_size), (void*)(&size), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmRead,CMockString_data);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_data, data, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.nvmRead_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.nvmRead_CallbackFunctionPointer(nvmInstance, address, size, data, Mock.nvmRead_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nvmRead(CMOCK_nvmRead_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance, size_t address, size_t size, uint8_t* data);
void CMockExpectParameters_nvmRead(CMOCK_nvmRead_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance, size_t address, size_t size, uint8_t* data)
{
  cmock_call_instance->Expected_nvmInstance = nvmInstance;
  memcpy((void*)(&cmock_call_instance->Expected_address), (void*)(&address),
         sizeof(size_t[sizeof(address) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_size), (void*)(&size),
         sizeof(size_t[sizeof(size) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  cmock_call_instance->Expected_data = data;
}

void nvmRead_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmRead_CALL_INSTANCE));
  CMOCK_nvmRead_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmRead_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmRead_CallInstance = CMock_Guts_MemChain(Mock.nvmRead_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void nvmRead_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmInstance* nvmInstance, size_t address, size_t size, uint8_t* data, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmRead_CALL_INSTANCE));
  CMOCK_nvmRead_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmRead_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmRead_CallInstance = CMock_Guts_MemChain(Mock.nvmRead_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_nvmRead(cmock_call_instance, nvmInstance, address, size, data);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(enum nvmStatus[sizeof(cmock_to_return) == sizeof(enum nvmStatus) ? 1 : -1])); /* add enum nvmStatus to :treat_as_array if this causes an error */
}

void nvmRead_AddCallback(CMOCK_nvmRead_CALLBACK Callback)
{
  Mock.nvmRead_CallbackBool = (char)1;
  Mock.nvmRead_CallbackFunctionPointer = Callback;
}

void nvmRead_Stub(CMOCK_nvmRead_CALLBACK Callback)
{
  Mock.nvmRead_CallbackBool = (char)0;
  Mock.nvmRead_CallbackFunctionPointer = Callback;
}

enum nvmStatus nvmErasePages(struct nvmInstance* nvmInstance, size_t pageNumber, size_t pagesCount)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nvmErasePages_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_nvmErasePages);
  cmock_call_instance = (CMOCK_nvmErasePages_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nvmErasePages_CallInstance);
  Mock.nvmErasePages_CallInstance = CMock_Guts_MemNext(Mock.nvmErasePages_CallInstance);
  if (!Mock.nvmErasePages_CallbackBool &&
      Mock.nvmErasePages_CallbackFunctionPointer != NULL)
  {
    enum nvmStatus cmock_cb_ret = Mock.nvmErasePages_CallbackFunctionPointer(nvmInstance, pageNumber, pagesCount, Mock.nvmErasePages_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  {
    UNITY_SET_DETAILS(CMockString_nvmErasePages,CMockString_nvmInstance);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_nvmInstance, nvmInstance, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmErasePages,CMockString_pageNumber);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_pageNumber), (void*)(&pageNumber), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_nvmErasePages,CMockString_pagesCount);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_pagesCount), (void*)(&pagesCount), sizeof(size_t), cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.nvmErasePages_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.nvmErasePages_CallbackFunctionPointer(nvmInstance, pageNumber, pagesCount, Mock.nvmErasePages_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nvmErasePages(CMOCK_nvmErasePages_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance, size_t pageNumber, size_t pagesCount);
void CMockExpectParameters_nvmErasePages(CMOCK_nvmErasePages_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance, size_t pageNumber, size_t pagesCount)
{
  cmock_call_instance->Expected_nvmInstance = nvmInstance;
  memcpy((void*)(&cmock_call_instance->Expected_pageNumber), (void*)(&pageNumber),
         sizeof(size_t[sizeof(pageNumber) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
  memcpy((void*)(&cmock_call_instance->Expected_pagesCount), (void*)(&pagesCount),
         sizeof(size_t[sizeof(pagesCount) == sizeof(size_t) ? 1 : -1])); /* add size_t to :treat_as_array if this causes an error */
}

void nvmErasePages_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmErasePages_CALL_INSTANCE));
  CMOCK_nvmErasePages_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmErasePages_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmErasePages_CallInstance = CMock_Guts_MemChain(Mock.nvmErasePages_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void nvmErasePages_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmInstance* nvmInstance, size_t pageNumber, size_t pagesCount, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmErasePages_CALL_INSTANCE));
  CMOCK_nvmErasePages_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmErasePages_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmErasePages_CallInstance = CMock_Guts_MemChain(Mock.nvmErasePages_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_nvmErasePages(cmock_call_instance, nvmInstance, pageNumber, pagesCount);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(enum nvmStatus[sizeof(cmock_to_return) == sizeof(enum nvmStatus) ? 1 : -1])); /* add enum nvmStatus to :treat_as_array if this causes an error */
}

void nvmErasePages_AddCallback(CMOCK_nvmErasePages_CALLBACK Callback)
{
  Mock.nvmErasePages_CallbackBool = (char)1;
  Mock.nvmErasePages_CallbackFunctionPointer = Callback;
}

void nvmErasePages_Stub(CMOCK_nvmErasePages_CALLBACK Callback)
{
  Mock.nvmErasePages_CallbackBool = (char)0;
  Mock.nvmErasePages_CallbackFunctionPointer = Callback;
}

enum nvmStatus nvmDeinit(struct nvmInstance** nvmInstance)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nvmDeinit_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_nvmDeinit);
  cmock_call_instance = (CMOCK_nvmDeinit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nvmDeinit_CallInstance);
  Mock.nvmDeinit_CallInstance = CMock_Guts_MemNext(Mock.nvmDeinit_CallInstance);
  if (!Mock.nvmDeinit_CallbackBool &&
      Mock.nvmDeinit_CallbackFunctionPointer != NULL)
  {
    enum nvmStatus cmock_cb_ret = Mock.nvmDeinit_CallbackFunctionPointer(nvmInstance, Mock.nvmDeinit_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  {
    UNITY_SET_DETAILS(CMockString_nvmDeinit,CMockString_nvmInstance);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_nvmInstance, nvmInstance, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.nvmDeinit_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.nvmDeinit_CallbackFunctionPointer(nvmInstance, Mock.nvmDeinit_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nvmDeinit(CMOCK_nvmDeinit_CALL_INSTANCE* cmock_call_instance, struct nvmInstance** nvmInstance);
void CMockExpectParameters_nvmDeinit(CMOCK_nvmDeinit_CALL_INSTANCE* cmock_call_instance, struct nvmInstance** nvmInstance)
{
  cmock_call_instance->Expected_nvmInstance = nvmInstance;
}

void nvmDeinit_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmDeinit_CALL_INSTANCE));
  CMOCK_nvmDeinit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmDeinit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmDeinit_CallInstance = CMock_Guts_MemChain(Mock.nvmDeinit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void nvmDeinit_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmInstance** nvmInstance, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmDeinit_CALL_INSTANCE));
  CMOCK_nvmDeinit_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmDeinit_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmDeinit_CallInstance = CMock_Guts_MemChain(Mock.nvmDeinit_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_nvmDeinit(cmock_call_instance, nvmInstance);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(enum nvmStatus[sizeof(cmock_to_return) == sizeof(enum nvmStatus) ? 1 : -1])); /* add enum nvmStatus to :treat_as_array if this causes an error */
}

void nvmDeinit_AddCallback(CMOCK_nvmDeinit_CALLBACK Callback)
{
  Mock.nvmDeinit_CallbackBool = (char)1;
  Mock.nvmDeinit_CallbackFunctionPointer = Callback;
}

void nvmDeinit_Stub(CMOCK_nvmDeinit_CALLBACK Callback)
{
  Mock.nvmDeinit_CallbackBool = (char)0;
  Mock.nvmDeinit_CallbackFunctionPointer = Callback;
}

enum nvmStatus nvmEraseAll(struct nvmInstance* nvmInstance)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nvmEraseAll_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_nvmEraseAll);
  cmock_call_instance = (CMOCK_nvmEraseAll_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nvmEraseAll_CallInstance);
  Mock.nvmEraseAll_CallInstance = CMock_Guts_MemNext(Mock.nvmEraseAll_CallInstance);
  if (!Mock.nvmEraseAll_CallbackBool &&
      Mock.nvmEraseAll_CallbackFunctionPointer != NULL)
  {
    enum nvmStatus cmock_cb_ret = Mock.nvmEraseAll_CallbackFunctionPointer(nvmInstance, Mock.nvmEraseAll_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  {
    UNITY_SET_DETAILS(CMockString_nvmEraseAll,CMockString_nvmInstance);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_nvmInstance, nvmInstance, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.nvmEraseAll_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.nvmEraseAll_CallbackFunctionPointer(nvmInstance, Mock.nvmEraseAll_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nvmEraseAll(CMOCK_nvmEraseAll_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance);
void CMockExpectParameters_nvmEraseAll(CMOCK_nvmEraseAll_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance)
{
  cmock_call_instance->Expected_nvmInstance = nvmInstance;
}

void nvmEraseAll_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmEraseAll_CALL_INSTANCE));
  CMOCK_nvmEraseAll_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmEraseAll_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmEraseAll_CallInstance = CMock_Guts_MemChain(Mock.nvmEraseAll_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void nvmEraseAll_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmInstance* nvmInstance, enum nvmStatus cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmEraseAll_CALL_INSTANCE));
  CMOCK_nvmEraseAll_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmEraseAll_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmEraseAll_CallInstance = CMock_Guts_MemChain(Mock.nvmEraseAll_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_nvmEraseAll(cmock_call_instance, nvmInstance);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(enum nvmStatus[sizeof(cmock_to_return) == sizeof(enum nvmStatus) ? 1 : -1])); /* add enum nvmStatus to :treat_as_array if this causes an error */
}

void nvmEraseAll_AddCallback(CMOCK_nvmEraseAll_CALLBACK Callback)
{
  Mock.nvmEraseAll_CallbackBool = (char)1;
  Mock.nvmEraseAll_CallbackFunctionPointer = Callback;
}

void nvmEraseAll_Stub(CMOCK_nvmEraseAll_CALLBACK Callback)
{
  Mock.nvmEraseAll_CallbackBool = (char)0;
  Mock.nvmEraseAll_CallbackFunctionPointer = Callback;
}

struct nvmDescription nvmGetInfo(struct nvmInstance* nvmInstance)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_nvmGetInfo_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_nvmGetInfo);
  cmock_call_instance = (CMOCK_nvmGetInfo_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.nvmGetInfo_CallInstance);
  Mock.nvmGetInfo_CallInstance = CMock_Guts_MemNext(Mock.nvmGetInfo_CallInstance);
  if (!Mock.nvmGetInfo_CallbackBool &&
      Mock.nvmGetInfo_CallbackFunctionPointer != NULL)
  {
    struct nvmDescription cmock_cb_ret = Mock.nvmGetInfo_CallbackFunctionPointer(nvmInstance, Mock.nvmGetInfo_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (!cmock_call_instance->ExpectAnyArgsBool)
  {
  {
    UNITY_SET_DETAILS(CMockString_nvmGetInfo,CMockString_nvmInstance);
    UNITY_TEST_ASSERT_EQUAL_PTR(cmock_call_instance->Expected_nvmInstance, nvmInstance, cmock_line, CMockStringMismatch);
  }
  }
  if (Mock.nvmGetInfo_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.nvmGetInfo_CallbackFunctionPointer(nvmInstance, Mock.nvmGetInfo_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_nvmGetInfo(CMOCK_nvmGetInfo_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance);
void CMockExpectParameters_nvmGetInfo(CMOCK_nvmGetInfo_CALL_INSTANCE* cmock_call_instance, struct nvmInstance* nvmInstance)
{
  cmock_call_instance->Expected_nvmInstance = nvmInstance;
}

void nvmGetInfo_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmDescription cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmGetInfo_CALL_INSTANCE));
  CMOCK_nvmGetInfo_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmGetInfo_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmGetInfo_CallInstance = CMock_Guts_MemChain(Mock.nvmGetInfo_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  cmock_call_instance->ReturnVal = cmock_to_return;
  cmock_call_instance->ExpectAnyArgsBool = (char)1;
}

void nvmGetInfo_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, struct nvmInstance* nvmInstance, struct nvmDescription cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_nvmGetInfo_CALL_INSTANCE));
  CMOCK_nvmGetInfo_CALL_INSTANCE* cmock_call_instance = (CMOCK_nvmGetInfo_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.nvmGetInfo_CallInstance = CMock_Guts_MemChain(Mock.nvmGetInfo_CallInstance, cmock_guts_index);
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ExpectAnyArgsBool = (char)0;
  CMockExpectParameters_nvmGetInfo(cmock_call_instance, nvmInstance);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(struct nvmDescription[sizeof(cmock_to_return) == sizeof(struct nvmDescription) ? 1 : -1])); /* add struct nvmDescription to :treat_as_array if this causes an error */
}

void nvmGetInfo_AddCallback(CMOCK_nvmGetInfo_CALLBACK Callback)
{
  Mock.nvmGetInfo_CallbackBool = (char)1;
  Mock.nvmGetInfo_CallbackFunctionPointer = Callback;
}

void nvmGetInfo_Stub(CMOCK_nvmGetInfo_CALLBACK Callback)
{
  Mock.nvmGetInfo_CallbackBool = (char)0;
  Mock.nvmGetInfo_CallbackFunctionPointer = Callback;
}

