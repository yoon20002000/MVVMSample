// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VM_Health.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class MVVMSAMPLE_API UVM_Health : public UMVVMViewModelBase
{
	GENERATED_BODY()
private:
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess=true))
	int32 CurrentHealth;
	UPROPERTY(BlueprintReadWrite, FieldNotify, Setter, Getter, meta=(AllowPrivateAccess=true))
	int32 MaxHealth;

public:
	UVM_Health();
	void SetCurrentHealth(const int32 InHealth)
	{
		if(UE_MVVM_SET_PROPERTY_VALUE(CurrentHealth, InHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
		}
	}
	int32 GetCurrentHealth() const
	{
		return CurrentHealth;
	}
	void SetMaxHealth(const int32 InHealth)
	{
		if(UE_MVVM_SET_PROPERTY_VALUE(MaxHealth, InHealth))
		{
			UE_MVVM_BROADCAST_FIELD_VALUE_CHANGED(GetHealthPercent);
		}
	}
	int32 GetMaxHealth() const
	{
		return MaxHealth;
	}
	UFUNCTION(BlueprintPure, FieldNotify)
	float GetHealthPercent() const
	{
		if(MaxHealth!=0)
		{
			return static_cast<float>(CurrentHealth)/static_cast<float>(MaxHealth);
		}
		else 
		{
			return 0;
		}
	}
};
