// Copyright 2023 Xsolla Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class UXsollaUIBuilderSettings;

/**
 * Xsolla UIBuilder Module
 */
class FXsollaUIBuilderModule : public IModuleInterface
{

public:
	/** IModuleInterface implementation. */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/**
	 * Singleton-like access to this module's interface.  This is just for convenience!
	 * Beware of calling this during the shutdown phase, though.  Your module might already be unloaded.
	 *
	 * @return Returns singleton instance, loading the module on demand if needed.
	 */
	static inline FXsollaUIBuilderModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FXsollaUIBuilderModule>(ModuleName);
	}

	/**
	 * Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	 *
	 * @return True if the module is loaded and ready to use.
	 */
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded(ModuleName);
	}

	/** Getter for internal settings object to support runtime configuration changes */
	UXsollaUIBuilderSettings* GetSettings() const;

	/** Module name. */
	static const FName ModuleName;

private:
	/** Settings. */
	UXsollaUIBuilderSettings* XsollaUIBuilderSettings;
};
