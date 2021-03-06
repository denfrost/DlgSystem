// Copyright 2017-2018 Csaba Molnar, Daniel Butum
#pragma once

#include "CoreMinimal.h"

#include "DlgManager.h"
#include "DlgTreeViewHelper.h"

class UDlgDialogue;

/** Structure that holds the common properties of a Variable. */
class DLGSYSTEM_API FDlgTreeViewVariableProperties
{
public:
	FDlgTreeViewVariableProperties(const TSet<TWeakObjectPtr<const UDlgDialogue>>& InDialogues) : Dialogues(InDialogues) {}
	virtual ~FDlgTreeViewVariableProperties() {}

	// Dialogues:
	virtual void AddDialogue(TWeakObjectPtr<const UDlgDialogue> Dialogue) { Dialogues.Add(Dialogue); }
	const TSet<TWeakObjectPtr<const UDlgDialogue>>& GetDialogues() const { return Dialogues; }

	/** Sorts all the properties it can */
	virtual void Sort()
	{
		Dialogues.Sort(FDlgTreeViewHelper::PredicateSortDialogueWeakPtrAlphabeticallyAscending);
	}

protected:
	/** Dialogues that contain this variable property */
	TSet<TWeakObjectPtr<const UDlgDialogue>> Dialogues;
};
