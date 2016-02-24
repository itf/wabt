/*
 * Copyright 2016 WebAssembly Community Group participants
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WASM_COMMON_H_
#define WASM_COMMON_H_

#include <stddef.h>

#ifdef __cplusplus
#define EXTERN_C extern "C"
#define EXTERN_C_BEGIN extern "C" {
#define EXTERN_C_END }
#else
#define EXTERN_C
#define EXTERN_C_BEGIN
#define EXTERN_C_END
#endif

#define WARN_UNUSED __attribute__ ((warn_unused_result))

typedef enum WasmResult {
  WASM_OK,
  WASM_ERROR,
} WasmResult;

typedef struct WasmStringSlice {
  const char* start;
  size_t length;
} WasmStringSlice;

typedef struct WasmLocation {
  const char* filename;
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} WasmLocation;

/* matches binary format, do not change */
typedef enum WasmType {
  WASM_TYPE_VOID,
  WASM_TYPE_I32,
  WASM_TYPE_I64,
  WASM_TYPE_F32,
  WASM_TYPE_F64,
  WASM_NUM_TYPES,
} WasmType;

enum { WASM_USE_NATURAL_ALIGNMENT = 0xFFFFFFFF };

typedef enum WasmUnaryOpType {
  WASM_UNARY_OP_TYPE_F32_ABS,
  WASM_UNARY_OP_TYPE_F32_CEIL,
  WASM_UNARY_OP_TYPE_F32_FLOOR,
  WASM_UNARY_OP_TYPE_F32_NEAREST,
  WASM_UNARY_OP_TYPE_F32_NEG,
  WASM_UNARY_OP_TYPE_F32_SQRT,
  WASM_UNARY_OP_TYPE_F32_TRUNC,
  WASM_UNARY_OP_TYPE_F64_ABS,
  WASM_UNARY_OP_TYPE_F64_CEIL,
  WASM_UNARY_OP_TYPE_F64_FLOOR,
  WASM_UNARY_OP_TYPE_F64_NEAREST,
  WASM_UNARY_OP_TYPE_F64_NEG,
  WASM_UNARY_OP_TYPE_F64_SQRT,
  WASM_UNARY_OP_TYPE_F64_TRUNC,
  WASM_UNARY_OP_TYPE_I32_CLZ,
  WASM_UNARY_OP_TYPE_I32_CTZ,
  WASM_UNARY_OP_TYPE_I32_NOT,
  WASM_UNARY_OP_TYPE_I32_POPCNT,
  WASM_UNARY_OP_TYPE_I64_CLZ,
  WASM_UNARY_OP_TYPE_I64_CTZ,
  WASM_UNARY_OP_TYPE_I64_POPCNT,
  WASM_NUM_UNARY_OP_TYPES,
} WasmUnaryOpType;

typedef enum WasmBinaryOpType {
  WASM_BINARY_OP_TYPE_F32_ADD,
  WASM_BINARY_OP_TYPE_F32_COPYSIGN,
  WASM_BINARY_OP_TYPE_F32_DIV,
  WASM_BINARY_OP_TYPE_F32_MAX,
  WASM_BINARY_OP_TYPE_F32_MIN,
  WASM_BINARY_OP_TYPE_F32_MUL,
  WASM_BINARY_OP_TYPE_F32_SUB,
  WASM_BINARY_OP_TYPE_F64_ADD,
  WASM_BINARY_OP_TYPE_F64_COPYSIGN,
  WASM_BINARY_OP_TYPE_F64_DIV,
  WASM_BINARY_OP_TYPE_F64_MAX,
  WASM_BINARY_OP_TYPE_F64_MIN,
  WASM_BINARY_OP_TYPE_F64_MUL,
  WASM_BINARY_OP_TYPE_F64_SUB,
  WASM_BINARY_OP_TYPE_I32_ADD,
  WASM_BINARY_OP_TYPE_I32_AND,
  WASM_BINARY_OP_TYPE_I32_DIV_S,
  WASM_BINARY_OP_TYPE_I32_DIV_U,
  WASM_BINARY_OP_TYPE_I32_MUL,
  WASM_BINARY_OP_TYPE_I32_OR,
  WASM_BINARY_OP_TYPE_I32_REM_S,
  WASM_BINARY_OP_TYPE_I32_REM_U,
  WASM_BINARY_OP_TYPE_I32_SHL,
  WASM_BINARY_OP_TYPE_I32_SHR_S,
  WASM_BINARY_OP_TYPE_I32_SHR_U,
  WASM_BINARY_OP_TYPE_I32_SUB,
  WASM_BINARY_OP_TYPE_I32_XOR,
  WASM_BINARY_OP_TYPE_I64_ADD,
  WASM_BINARY_OP_TYPE_I64_AND,
  WASM_BINARY_OP_TYPE_I64_DIV_S,
  WASM_BINARY_OP_TYPE_I64_DIV_U,
  WASM_BINARY_OP_TYPE_I64_MUL,
  WASM_BINARY_OP_TYPE_I64_OR,
  WASM_BINARY_OP_TYPE_I64_REM_S,
  WASM_BINARY_OP_TYPE_I64_REM_U,
  WASM_BINARY_OP_TYPE_I64_SHL,
  WASM_BINARY_OP_TYPE_I64_SHR_S,
  WASM_BINARY_OP_TYPE_I64_SHR_U,
  WASM_BINARY_OP_TYPE_I64_SUB,
  WASM_BINARY_OP_TYPE_I64_XOR,
  WASM_NUM_BINARY_OP_TYPES,
} WasmBinaryOpType;

typedef enum WasmCompareOpType {
  WASM_COMPARE_OP_TYPE_F32_EQ,
  WASM_COMPARE_OP_TYPE_F32_GE,
  WASM_COMPARE_OP_TYPE_F32_GT,
  WASM_COMPARE_OP_TYPE_F32_LE,
  WASM_COMPARE_OP_TYPE_F32_LT,
  WASM_COMPARE_OP_TYPE_F32_NE,
  WASM_COMPARE_OP_TYPE_F64_EQ,
  WASM_COMPARE_OP_TYPE_F64_GE,
  WASM_COMPARE_OP_TYPE_F64_GT,
  WASM_COMPARE_OP_TYPE_F64_LE,
  WASM_COMPARE_OP_TYPE_F64_LT,
  WASM_COMPARE_OP_TYPE_F64_NE,
  WASM_COMPARE_OP_TYPE_I32_EQ,
  WASM_COMPARE_OP_TYPE_I32_GE_S,
  WASM_COMPARE_OP_TYPE_I32_GE_U,
  WASM_COMPARE_OP_TYPE_I32_GT_S,
  WASM_COMPARE_OP_TYPE_I32_GT_U,
  WASM_COMPARE_OP_TYPE_I32_LE_S,
  WASM_COMPARE_OP_TYPE_I32_LE_U,
  WASM_COMPARE_OP_TYPE_I32_LT_S,
  WASM_COMPARE_OP_TYPE_I32_LT_U,
  WASM_COMPARE_OP_TYPE_I32_NE,
  WASM_COMPARE_OP_TYPE_I64_EQ,
  WASM_COMPARE_OP_TYPE_I64_GE_S,
  WASM_COMPARE_OP_TYPE_I64_GE_U,
  WASM_COMPARE_OP_TYPE_I64_GT_S,
  WASM_COMPARE_OP_TYPE_I64_GT_U,
  WASM_COMPARE_OP_TYPE_I64_LE_S,
  WASM_COMPARE_OP_TYPE_I64_LE_U,
  WASM_COMPARE_OP_TYPE_I64_LT_S,
  WASM_COMPARE_OP_TYPE_I64_LT_U,
  WASM_COMPARE_OP_TYPE_I64_NE,
  WASM_NUM_COMPARE_OP_TYPES,
} WasmCompareOpType;

typedef enum WasmMemOpType {
  WASM_MEM_OP_TYPE_F32_LOAD,
  WASM_MEM_OP_TYPE_F32_STORE,
  WASM_MEM_OP_TYPE_F64_LOAD,
  WASM_MEM_OP_TYPE_F64_STORE,
  WASM_MEM_OP_TYPE_I32_LOAD,
  WASM_MEM_OP_TYPE_I32_LOAD8_S,
  WASM_MEM_OP_TYPE_I32_LOAD8_U,
  WASM_MEM_OP_TYPE_I32_LOAD16_S,
  WASM_MEM_OP_TYPE_I32_LOAD16_U,
  WASM_MEM_OP_TYPE_I32_STORE,
  WASM_MEM_OP_TYPE_I32_STORE8,
  WASM_MEM_OP_TYPE_I32_STORE16,
  WASM_MEM_OP_TYPE_I64_LOAD,
  WASM_MEM_OP_TYPE_I64_LOAD8_S,
  WASM_MEM_OP_TYPE_I64_LOAD8_U,
  WASM_MEM_OP_TYPE_I64_LOAD16_S,
  WASM_MEM_OP_TYPE_I64_LOAD16_U,
  WASM_MEM_OP_TYPE_I64_LOAD32_S,
  WASM_MEM_OP_TYPE_I64_LOAD32_U,
  WASM_MEM_OP_TYPE_I64_STORE,
  WASM_MEM_OP_TYPE_I64_STORE8,
  WASM_MEM_OP_TYPE_I64_STORE16,
  WASM_MEM_OP_TYPE_I64_STORE32,
  WASM_NUM_MEM_OP_TYPES,
} WasmMemOpType;

typedef enum WasmConvertOpType {
  WASM_CONVERT_OP_TYPE_F32_CONVERT_S_I32,
  WASM_CONVERT_OP_TYPE_F32_CONVERT_S_I64,
  WASM_CONVERT_OP_TYPE_F32_CONVERT_U_I32,
  WASM_CONVERT_OP_TYPE_F32_CONVERT_U_I64,
  WASM_CONVERT_OP_TYPE_F32_DEMOTE_F64,
  WASM_CONVERT_OP_TYPE_F64_CONVERT_S_I32,
  WASM_CONVERT_OP_TYPE_F64_CONVERT_S_I64,
  WASM_CONVERT_OP_TYPE_F64_CONVERT_U_I32,
  WASM_CONVERT_OP_TYPE_F64_CONVERT_U_I64,
  WASM_CONVERT_OP_TYPE_F64_PROMOTE_F32,
  WASM_CONVERT_OP_TYPE_I32_TRUNC_S_F32,
  WASM_CONVERT_OP_TYPE_I32_TRUNC_S_F64,
  WASM_CONVERT_OP_TYPE_I32_TRUNC_U_F32,
  WASM_CONVERT_OP_TYPE_I32_TRUNC_U_F64,
  WASM_CONVERT_OP_TYPE_I32_WRAP_I64,
  WASM_CONVERT_OP_TYPE_I64_EXTEND_S_I32,
  WASM_CONVERT_OP_TYPE_I64_EXTEND_U_I32,
  WASM_CONVERT_OP_TYPE_I64_TRUNC_S_F32,
  WASM_CONVERT_OP_TYPE_I64_TRUNC_S_F64,
  WASM_CONVERT_OP_TYPE_I64_TRUNC_U_F32,
  WASM_CONVERT_OP_TYPE_I64_TRUNC_U_F64,
  WASM_CONVERT_OP_TYPE_F32_REINTERPRET_I32,
  WASM_CONVERT_OP_TYPE_F64_REINTERPRET_I64,
  WASM_CONVERT_OP_TYPE_I32_REINTERPRET_F32,
  WASM_CONVERT_OP_TYPE_I64_REINTERPRET_F64,
  WASM_NUM_CONVERT_OP_TYPES,
} WasmConvertOpType;

typedef enum WasmTargetType {
  WASM_TARGET_TYPE_CASE,
  WASM_TARGET_TYPE_BR,
} WasmTargetType;

#endif /* WASM_COMMON_H_ */
