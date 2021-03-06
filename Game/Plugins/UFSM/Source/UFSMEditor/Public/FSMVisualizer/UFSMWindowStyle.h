////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///			Copyright 2017 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Editor/UnrealEd/Public/ClassIconFinder.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class FSMWindowStyle {
private:
	static TSharedPtr<FSlateStyleSet> StyleSet;
	static FString InContent(const FString &RelativePath, const TCHAR* Extension);
public:
	static void Initialize();
	static void Shutdown();
	static void ReloadTextures();
	static FName GetStyleSetName();
	static TSharedPtr<ISlateStyle> Get();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
