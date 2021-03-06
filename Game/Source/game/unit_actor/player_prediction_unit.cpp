// Fill out your copyright notice in the Description page of Project Settings.

#include "player_prediction_unit.h"
#include "gamecore_include.h"

#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Engine/SkeletalMesh.h"
#include "Engine/AssetManager.h"

// Sets default values.
A_player_prediction_unit::A_player_prediction_unit(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	add_mesh_componenet((int32)E_unit_parts_type::hair, m_p_mesh_hair = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("hair")));
	add_mesh_componenet((int32)E_unit_parts_type::head, m_p_mesh_head = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("head")));
	add_mesh_componenet((int32)E_unit_parts_type::upper, m_p_mesh_upper = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("upper")));
	add_mesh_componenet((int32)E_unit_parts_type::lower, m_p_mesh_lower = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("lower")));
	add_mesh_componenet((int32)E_unit_parts_type::glove, m_p_mesh_glove = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("glove")));
	add_mesh_componenet((int32)E_unit_parts_type::shoes, m_p_mesh_shoes = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("shoes")));
}

// Called when the game starts or when spawned
void A_player_prediction_unit::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void A_player_prediction_unit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void A_player_prediction_unit::_initialize(uint32 _uiUniqIndex)
{
	Super::_initialize(_uiUniqIndex);

	int i_property = 50;
	change_mesh((int32)E_unit_parts_type::hair, "SkeletalMesh'/Game/pridiction/character/female/mesh/hair.hair'", i_property);
	change_mesh((int32)E_unit_parts_type::head, "SkeletalMesh'/Game/pridiction/character/female/mesh/head.head'", i_property);
	change_mesh((int32)E_unit_parts_type::upper, "SkeletalMesh'/Game/pridiction/character/female/mesh/upper.upper'", i_property);
	change_mesh((int32)E_unit_parts_type::lower, "SkeletalMesh'/Game/pridiction/character/female/mesh/lower.lower'", i_property);
	change_mesh((int32)E_unit_parts_type::glove, "SkeletalMesh'/Game/pridiction/character/female/mesh/glove.glove'", i_property);
	change_mesh((int32)E_unit_parts_type::shoes, "SkeletalMesh'/Game/pridiction/character/female/mesh/shoes.shoes'", i_property);

	set_anim_instance("AnimBlueprint'/Game/pridiction/character/female/animation/female_anim_bp.female_anim_bp_C'");
}

void A_player_prediction_unit::_reset()
{
	Super::_reset();
}

/*
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Barbarous.SK_CharM_Barbarous'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/sk_CharM_Base.sk_CharM_Base'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Bladed.SK_CharM_Bladed'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Forge.SK_CharM_Forge'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_FrostGiant.SK_CharM_FrostGiant'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Golden.SK_CharM_Golden'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Natural.SK_CharM_Natural'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Pit.SK_CharM_Pit'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Ragged0.SK_CharM_Ragged0'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_RaggedElite.SK_CharM_RaggedElite'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Ram.SK_CharM_Ram'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Robo.SK_CharM_Robo'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Shell.SK_CharM_Shell'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_solid.SK_CharM_solid'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Standard.SK_CharM_Standard'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Tusk.SK_CharM_Tusk'");
_Assets.Add("SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Warrior.SK_CharM_Warrior'");
*/