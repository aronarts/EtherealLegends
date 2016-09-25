// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "ReturnPortal.h"

AReturnPortal::AReturnPortal(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USoundCue> PortalAudioObject(TEXT("SoundCue'/Game/Audio/Impacts/PortalExplosion_Cue.PortalExplosion_Cue'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> HolospireParticle(TEXT("ParticleSystem'/Game/Effects/Holograms/HologramSpire.HologramSpire'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> HoloIdleParticle(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Mobile/Misc/AltarFX_ExpAdd.AltarFX_ExpAdd'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> BurstParticle(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Monsters/FX_Monster_Ausar/P_AU_Trap_Impact.P_AU_Trap_Impact'"));
	
	// Set Default Objects
	S_PortalAudio = PortalAudioObject.Object;
	P_HolospireFX = HolospireParticle.Object;
	P_HoloIdleFX = HoloIdleParticle.Object;
	P_BurstFX = BurstParticle.Object;
	
	InteractBox->SetBoxExtent(FVector(100, 100, 100));  // scale up the interact box

	// Create objects
	PortalAudio = ObjectInitializer.CreateDefaultSubobject<UAudioComponent>(this, TEXT("PortalAudio"));
	PortalAudio->SetupAttachment(RootComponent);
	PortalAudio->Sound = S_PortalAudio;
	PortalAudio->bAutoActivate = false;

	HolospireFX = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("HolospireFX"));
	HolospireFX->SetupAttachment(RootComponent);
	HolospireFX->Template = P_HolospireFX;
	HolospireFX->bAutoActivate = false;
	HolospireFX->SetRelativeScale3D(FVector(3.0f, 3.0f, 3.0f));

	HoloIdleFX = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("HoloIdleFX"));
	HoloIdleFX->SetupAttachment(RootComponent);
	HoloIdleFX->Template = P_HoloIdleFX;
	HoloIdleFX->bAutoActivate = true;
	HoloIdleFX->SetRelativeLocation(FVector(0, 0, -25));
	HoloIdleFX->SetRelativeScale3D(FVector(4.0f, 4.0f, 4.0f));

	BurstFX = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("BurstFX"));
	BurstFX->SetupAttachment(RootComponent);
	BurstFX->Template = P_BurstFX;
	BurstFX->bAutoActivate = false;
	BurstFX->SetRelativeScale3D(FVector(6.0f, 6.0f, 6.0f));

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Open;

	DoInteract.AddDynamic(this, &AReturnPortal::Interact); // bind interact
}

// Called when the game starts or when spawned
void AReturnPortal::BeginPlay()
{
	Super::BeginPlay();
}

// Do a Burst effect when the portal is activated
void AReturnPortal::DoBurstEffect()
{
	HolospireFX->Activate();
	BurstFX->Activate();
	PortalAudio->Play();
	InteractingPlayer->DoFlight = true;

	// Load Arcadia after a short delay
	FTimerHandle LoadTimer;
	GetWorldTimerManager().SetTimer(LoadTimer, this, &AReturnPortal::LoadArcadia, 3.0f, false);
}

void AReturnPortal::LoadArcadia()
{
	InteractingPlayer->EtherealGameInstance->LoadNewRealm(ERealms::R_Arcadia);
}

// Interact with this NPC
void AReturnPortal::Interact()
{
	IsUsable = false;
	DoBurstEffect();

	// TO DO : Hide Battle HUD
}