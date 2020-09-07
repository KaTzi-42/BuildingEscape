// Copyright Vadym Krysevych 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:	
	// Sets default values for this component's properties
	UGrabber();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	float Reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	//�������� ��� � ������� ������
	void Grab();
	//����� ������� grab �������� 
	void Release();

	//������������� ������������� ���. ���������
	void FindPhysicsHandleComponent();
	//������������� ������������� ������� ���������
	void SetupInputComponent();
	//���������� ������ ��� ���� � ������� ����
	const FHitResult GetFirstPhysicsBodyInReach();

	//return start of reach (ray) line
	FVector GetReachLineStart();
	//return end of reach (ray) line
	FVector GetReachLineEnd();
	//return rotation 
	FRotator GetPlayerRotator();
};