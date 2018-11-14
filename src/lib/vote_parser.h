/*******************************************************************************
*   (c) 2018 ZondaX GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/

#pragma once
#include <inttypes.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  uint8_t Type;
  int64_t Height;
  int8_t Round;
} vote_t;

typedef enum {
  parse_ok = 0,
  parse_unexpected_buffer_end = 1,
  parse_unexpected_field = 2,
  parse_unexpected_wire_type = 3,
  parse_unexpected_type_value = 4,
  parse_unexpected_height_value = 5,
  parse_unexpected_round_value = 6
} parse_error_t;

parse_error_t vote_amino_parse(uint8_t *buffer, size_t size, vote_t *vote);

#ifdef __cplusplus
}
#endif