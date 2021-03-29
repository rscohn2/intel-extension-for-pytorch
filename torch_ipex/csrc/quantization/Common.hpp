#pragma once

#include <ATen/Tensor.h>

namespace torch_ipex {

bool check_int8_calibration();
void insert_or_updata_observer(const at::TensorList &inputs,
                               const at::TensorList &ouputs,
                               std::string op_name,
                               int64_t ops_id,
                               std::vector<std::string> inputs_flow,
                               std::vector<std::string> outputs_flow);

void insert_or_updata_observer(const at::TensorList &inputs,
                               const at::TensorList &ouputs,
                               const at::Tensor& weight,
                               std::string op_name, int64_t ops_id,
                               std::vector<std::string> inputs_flow,
                               std::vector<std::string> outputs_flow);

std::vector<std::vector<float>> get_int8_scales(std::vector<bool> i_uint8_used,
                                                std::vector<bool> o_uint8_used,
                                                const int64_t ops_id);

std::vector<float> get_int8_weight_scales(const int64_t ops_id);

bool get_int8_quantized_status(const int64_t ops_id);

std::tuple<bool, bool> get_int8_insert_quantized_status(const int64_t ops_id);

}