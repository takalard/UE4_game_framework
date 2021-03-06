/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////
///			Copyright 2017 (C) Bruno Xavier B. Leite
//////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "UFSMGraphWidget.h"

#include "UFSMGraph.h"
#include "../UFSMEditorShared.h"
#include "Runtime/Engine/Classes/EdGraph/EdGraphSchema.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

UFSMGraphWidget::~UFSMGraphWidget() {
	if (!GExitPurge) {
		if (ensure(FSMGraph.Get())) {
			FSMGraph.Get()->RemoveFromRoot();
		}
	}
}

void UFSMGraphWidget::Construct(const FArguments& InArgs) {
	FSMGraph = NewObject<UFSMGraph>(UFSMGraph::StaticClass());
	FSMGraph.Get()->Schema = UEdGraphSchema::StaticClass();
	FSMGraph.Get()->AddToRoot();
	//
	ParentGraphEditor = SNew(SGraphEditor)
	.GraphToEdit(FSMGraph.Get());
	ChildSlot
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			[
				ParentGraphEditor.ToSharedRef()
			]
		]
	];
}

void UFSMGraphWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) {
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
	FSMGraph.Get()->UpdateGraph();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
