// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "gamecore_minimal.h"

#include "Engine/StreamableManager.h"

#include "resource_loader.h"
#include "resource_manager.generated.h"

//------------------------------------------------------------------------------------------------------
// 앞으로 해야할 것 들
// 1. Actor의 경우 거리 소팅        완료
// 2. 비동기, 동기 그룹 나누기		
// 3. 우선순위 property 작업		완료
//------------------------------------------------------------------------------------------------------

UCLASS()
class GAMECORE_API U_resource_manager : public UObject, public F_singleton<U_resource_manager>
{
	GENERATED_BODY()

	struct F_resource_loader {
	public:	F_resource_loader(U_resource_loader* _p_loader) { p_loader = _p_loader; }
	public: U_resource_loader* p_loader = nullptr;
			U_resource_loader* get() { return p_loader; }
	};

public:
	virtual void _initialize();
	virtual void _reset();
	virtual void _tick(float _f_delta_seconds);

private:
	int32									 m_i_resource_load_capacity = 100;	
	TArray<F_resource_loader>				 m_load_list;
	TMap<int32, TArray<F_resource_loader>*>  m_map_wait_list;

	FStreamableManager m_loadder;
	
public:
	void set_resource_load_capacity(int32 _i_capacity) { m_i_resource_load_capacity = _i_capacity; }
	void load_resource(const F_load_resource_desc& _desc, delegate_resource_load_complete _delegate_load_complete, delegate_resource_load_fail _delegate_load_fail, bool _b_sort = false);
	void clear_load_list();

public:
	FStreamableManager& get_streamable_manager() { return _get_instance()->m_loadder; }
};
