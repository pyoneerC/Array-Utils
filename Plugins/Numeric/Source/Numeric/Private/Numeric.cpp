// © 2024 Maximo Comperatore. All Rights Reserved.

#include "Numeric.h"

#define LOCTEXT_NAMESPACE "FNumericModule"

void FNumericModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FNumericModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNumericModule, Numeric)