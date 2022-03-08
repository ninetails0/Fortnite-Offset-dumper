#include "FortUpdater.h"
#include "spoof_call.h"
#include <Windows.h>
#include <iostream>
#include "Memory.h"
#include "Storing.h"

#define RELATIVE_ADDR(addr, size) ((PBYTE)((UINT_PTR)(addr) + *(PINT)((UINT_PTR)(addr) + ((size) - sizeof(INT))) + (size)))

VOID Main()
{
	AllocConsole();
	static_cast<VOID>(freopen("CONIN$", "r", stdin));
	static_cast<VOID>(freopen("CONOUT$", "w", stdout));
	static_cast<VOID>(freopen("CONOUT$", "w", stderr));

	uintptr_t UObjectArray = (uintptr_t)MemoryHelper::Pattern::PatternScan(("48 8B 05 ? ? ? ? 48 8B 0C C8 48 8B 04 D1"));
	UObjectArray = reinterpret_cast<uintptr_t>(RELATIVE_ADDR(UObjectArray, 7));
	uintptr_t GetNameByIndex = (uintptr_t)MemoryHelper::Pattern::PatternScan(("48 89 5C 24 20 56 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 84 24 30 08")); //48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 56 48 81 EC ? ? ? ? 48 8B 05 
	FortUpdater* Updater = new FortUpdater();

	if (Updater->Init(UObjectArray, GetNameByIndex))
	{
		Offsets::Levels = Updater->FindOffset("World", "Levels");
		Offsets::PersistentLevel = Updater->FindOffset(("World"), ("PersistentLevel"));
		Offsets::LocalPlayers = Updater->FindOffset("GameInstance", "LocalPlayers");
		Offsets::OwningGameInstance = Updater->FindOffset("World", "OwningGameInstance");
		Offsets::ControlRotation = Updater->FindOffset("Controller", "ControlRotation");
		Offsets::PlayerCameraManager = Updater->FindOffset("PlayerController", "PlayerCameraManager");
		Offsets::AcknowledgedPawn = Updater->FindOffset("PlayerController", "AcknowledgedPawn");
		Offsets::PlayerState = Updater->FindOffset("Pawn", "PlayerState");
		Offsets::RootComponent = Updater->FindOffset("Actor", "RootComponent");
		Offsets::Mesh = Updater->FindOffset("Character", "Mesh");
		Offsets::RelativeLocation = Updater->FindOffset("SceneComponent", "RelativeLocation");
		Offsets::ComponentVelocity = Updater->FindOffset("SceneComponent", "ComponentVelocity");
		Offsets::StaticMesh = Updater->FindOffset("StaticMeshComponent", "StaticMesh");
		Offsets::ComponentToWorld = Updater->FindOffset("StaticMeshComponent", "ComponentToWorld");
		Offsets::CachedWorldSpaceBounds = Updater->FindOffset("SkinnedMeshComponent", "CachedWorldSpaceBounds");
		Offsets::CustomTimeDilation = Updater->FindOffset("Actor", "CustomTimeDilation");
		Offsets::LastFireTimeVerified = Updater->FindOffset("FortWeapon", "LastFireTimeVerified");
		Offsets::LastFireTime = Updater->FindOffset("FortWeapon", "LastFireTime");
		Offsets::bIsDBNO = Updater->FindOffset("FortPawn", "bIsDBNO");
		Offsets::bIsDying = Updater->FindOffset("FortPawn", "bIsDying");
		Offsets::CharacterMovement = Updater->FindOffset("FortPawn", "CharacterMovement");
		Offsets::TeamIndex = Updater->FindOffset("FortPlayerStateAthena", "TeamIndex");
		Offsets::PrimaryPickupItemEntry = Updater->FindOffset("FortPickup", "PrimaryPickupItemEntry");
		Offsets::DisplayName = Updater->FindOffset("FortItemDefinition", "DisplayName");
		Offsets::Tier = Updater->FindOffset("FortItemDefinition", "Tier");
		Offsets::ItemDefinition = Updater->FindOffset("FortItemEntry", "ItemDefinition");
		Offsets::CurrentWeapon = Updater->FindOffset("FortPawn", "CurrentWeapon");
		Offsets::WeaponData = Updater->FindOffset("FortWeapon", "WeaponData");
		Offsets::RemoteViewPitch = Updater->FindOffset(("Pawn"), ("RemoteViewPitch"));
		Offsets::LastFireAbilityTime = Updater->FindOffset("FortWeapon", "LastFireAbilityTime");
		Offsets::WeaponStatHandle = Updater->FindOffset("FortWeaponItemDefinition", "WeaponStatHandle");
		Offsets::FireStartLoc = Updater->FindOffset("FortProjectileAthena", "FireStartLoc");
		Offsets::ReloadTime = Updater->FindOffset("FortBaseWeaponStats", "ReloadTime");
		Offsets::ReloadScale = Updater->FindOffset("FortBaseWeaponStats", "ReloadScale");
		Offsets::ChargeDownTime = Updater->FindOffset("FortBaseWeaponStats", "ChargeDownTime");
		Offsets::RecoilHoriz = Updater->FindOffset("FortRangedWeaponStats", "RecoilHoriz");
		Offsets::RecoilVert = Updater->FindOffset("FortRangedWeaponStats", "RecoilVert");
		Offsets::RecoilDownsightsMultiplier = Updater->FindOffset("FortRangedWeaponStats", "RecoilDownsightsMultiplier");

		Offsets::Spread = Updater->FindOffset("FortRangedWeaponStats", "Spread");
		Offsets::SpreadDownsights = Updater->FindOffset("FortRangedWeaponStats", "SpreadDownsights");
		Offsets::StandingStillSpreadMultiplier = Updater->FindOffset("FortRangedWeaponStats", "StandingStillSpreadMultiplier");
		Offsets::AthenaJumpingFallingSpreadMultiplier = Updater->FindOffset("FortRangedWeaponStats", "AthenaJumpingFallingSpreadMultiplier");
		Offsets::AthenaCrouchingSpreadMultiplier = Updater->FindOffset("FortRangedWeaponStats", "AthenaCrouchingSpreadMultiplier");
		Offsets::AthenaSprintingSpreadMultiplier = Updater->FindOffset("FortRangedWeaponStats", "RecoilDownsightsMultiplier");
		Offsets::MinSpeedForSpreadMultiplier = Updater->FindOffset("FortRangedWeaponStats", "MinSpeedForSpreadMultiplier");
		Offsets::MaxSpeedForSpreadMultiplier = Updater->FindOffset("FortRangedWeaponStats", "MaxSpeedForSpreadMultiplier");

		Offsets::bAlreadySearched = Updater->FindOffset("BuildingContainer", "bAlreadySearched");
	}
	else
	{

	}

	std::cout << "Engine::World::Levels: 0x" << std::hex << std::uppercase << Offsets::Levels << std::endl;
	std::cout << "Engine::World::PersistentLevel: 0x" << std::hex << std::uppercase << Offsets::PersistentLevel << std::endl;
	std::cout << "Engine::GameInstance::LocalPlayers: 0x" << std::hex << std::uppercase << Offsets::LocalPlayers << std::endl;
	std::cout << "Engine::World::OwningGameInstance: 0x" << std::hex << std::uppercase << Offsets::OwningGameInstance << std::endl;
	std::cout << "Engine::Controller::ControlRotation: 0x" << std::hex << std::uppercase << Offsets::ControlRotation << std::endl;
	std::cout << "Engine::PlayerController::PlayerCameraManager: 0x" << std::hex << std::uppercase << Offsets::PlayerCameraManager << std::endl;
	std::cout << "Engine::PlayerController::AcknowledgedPawn: 0x" << std::hex << std::uppercase << Offsets::AcknowledgedPawn << std::endl;
	std::cout << "Engine::Pawn::PlayerState: 0x" << std::hex << std::uppercase << Offsets::PlayerState << std::endl;
	std::cout << "Engine::Actor::RootComponent: 0x" << std::hex << std::uppercase << Offsets::RootComponent << std::endl;
	std::cout << "Engine::Character::Mesh: 0x" << std::hex << std::uppercase << Offsets::Mesh << std::endl;
	std::cout << "Engine::SceneComponent::RelativeLocation: 0x" << std::hex << std::uppercase << Offsets::RelativeLocation << std::endl;
	std::cout << "Engine::SceneComponent::ComponentVelocity: 0x" << std::hex << std::uppercase << Offsets::ComponentVelocity << std::endl;
	std::cout << "Engine::StaticMeshComponent::StaticMesh: 0x" << std::hex << std::uppercase << Offsets::StaticMesh << std::endl;
	std::cout << "Engine::SkinnedMeshComponent::CachedWorldSpaceBounds: 0x" << std::hex << std::uppercase << Offsets::CachedWorldSpaceBounds << std::endl;
	std::cout << "Engine::Actor::CustomTimeDilation: 0x" << std::hex << std::uppercase << Offsets::CustomTimeDilation << std::endl;

	std::cout << "FortniteGame::Offsets::FortniteGame::FortWeapon::LastFireTimeVerified: 0x" << std::hex << std::uppercase << Offsets::LastFireTimeVerified << std::endl;
	std::cout << "FortniteGame::Offsets::FortniteGame::FortWeapon::LastFireTime: 0x" << std::hex << std::uppercase << Offsets::LastFireTime << std::endl;
	std::cout << "FortniteGame::FortPawn::bIsDBNO: 0x" << std::hex << std::uppercase << Offsets::bIsDBNO << std::endl;
	std::cout << "FortniteGame::FortPawn::bIsDying: 0x" << std::hex << std::uppercase << Offsets::bIsDying << std::endl;
	std::cout << "FortniteGame::FortPawn::CharacterMovement: 0x" << std::hex << std::uppercase << Offsets::CharacterMovement << std::endl;
	std::cout << "FortniteGame::FortPlayerStateAthena::TeamIndex: 0x" << std::hex << std::uppercase << Offsets::TeamIndex << std::endl;
	std::cout << "FortniteGame::FortPickup::PrimaryPickupItemEntry: 0x" << std::hex << std::uppercase << Offsets::PrimaryPickupItemEntry << std::endl;
	std::cout << "FortniteGame::FortItemDefinition::DisplayName: 0x" << std::hex << std::uppercase << Offsets::DisplayName << std::endl;
	std::cout << "FortniteGame::FortItemDefinition::Tier: 0x" << std::hex << std::uppercase << Offsets::Tier << std::endl;
	std::cout << "FortniteGame::FortItemEntry::ItemDefinition: 0x" << std::hex << std::uppercase << Offsets::ItemDefinition << std::endl;
	std::cout << "FortniteGame::FortPawn::CurrentWeapon: 0x" << std::hex << std::uppercase << Offsets::CurrentWeapon << std::endl;
	std::cout << "FortniteGame::FortWeapon::WeaponData: 0x" << std::hex << std::uppercase << Offsets::WeaponData << std::endl;
	std::cout << "FortniteGame::FortWeapon::LastFireAbilityTime: 0x" << std::hex << std::uppercase << Offsets::LastFireAbilityTime << std::endl;
	std::cout << "FortniteGame::FortWeaponItemDefinition::WeaponStatHandle: 0x" << std::hex << std::uppercase << Offsets::WeaponStatHandle << std::endl;
	std::cout << "FortniteGame::FortProjectileAthena::FireStartLoc: 0x" << std::hex << std::uppercase << Offsets::FireStartLoc << std::endl;
	std::cout << "FortniteGame::FortBaseWeaponStats::ReloadTime: 0x" << std::hex << std::uppercase << Offsets::ReloadTime << std::endl;
	std::cout << "FortniteGame::FortBaseWeaponStats::ReloadScale: 0x" << std::hex << std::uppercase << Offsets::ReloadScale << std::endl;
	std::cout << "FortniteGame::FortBaseWeaponStats::ChargeDownTime: 0x" << std::hex << std::uppercase << Offsets::ChargeDownTime << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::RecoilHoriz: 0x" << std::hex << std::uppercase << Offsets::RecoilHoriz << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::RecoilVert: 0x" << std::hex << std::uppercase << Offsets::RecoilVert << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::RecoilDownsightsMultiplier: 0x" << std::hex << std::uppercase << Offsets::RecoilDownsightsMultiplier << std::endl;

	std::cout << "FortniteGame::FortRangedWeaponStats::Spread: 0x" << std::hex << std::uppercase << Offsets::Spread << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::SpreadDownsights: 0x" << std::hex << std::uppercase << Offsets::SpreadDownsights << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::StandingStillSpreadMultiplier: 0x" << std::hex << std::uppercase << Offsets::StandingStillSpreadMultiplier << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::AthenaJumpingFallingSpreadMultiplier: 0x" << std::hex << std::uppercase << Offsets::AthenaJumpingFallingSpreadMultiplier << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::AthenaCrouchingSpreadMultiplier: 0x" << std::hex << std::uppercase << Offsets::AthenaCrouchingSpreadMultiplier << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::AthenaSprintingSpreadMultiplier: 0x" << std::hex << std::uppercase << Offsets::AthenaSprintingSpreadMultiplier << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::MinSpeedForSpreadMultiplier: 0x" << std::hex << std::uppercase << Offsets::MinSpeedForSpreadMultiplier << std::endl;
	std::cout << "FortniteGame::FortRangedWeaponStats::MaxSpeedForSpreadMultiplier: 0x" << std::hex << std::uppercase << Offsets::MaxSpeedForSpreadMultiplier << std::endl;

	std::cout << "FortniteGame::BuildingContainer::bAlreadySearched: 0x" << std::hex << std::uppercase << Offsets::bAlreadySearched << std::endl;
	std::cout << "Offsets::Engine::Controller::RemoteViewPitch: 0x" << std::hex << std::uppercase << Offsets::RemoteViewPitch << std::endl;

}

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID reserved) {
	if (reason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(module);
		Main();
	}

	return TRUE;
}