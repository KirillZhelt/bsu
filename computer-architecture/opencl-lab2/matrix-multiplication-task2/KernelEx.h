#pragma once

#include "OpenCl.h"

class KernelEx
{
public:
	static cl::Kernel BuildFromSource(const cl::Device& device, const cl::Context& context, 
		const std::string& kernel_code, const std::string& kernel_name);

	static cl::Kernel BuildFromFile(const cl::Device& device, const cl::Context& context, 
		const std::string& kernel_file, const std::string& kernel_name);

};

