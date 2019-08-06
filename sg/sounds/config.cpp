////////////////////////////////////////////////////////////////////
//DeRap: sg_sounds\config.bin
//Produced from mikero's Dos Tools Dll version 7.27
//https://bytex.market/products/item/weodpphdknnzm70o0h8q/Mikero%27s%20Dos%20Tools
//'now' is Tue Aug 06 17:38:43 2019 : 'file' last modified on Mon Jul 29 11:21:05 2019
////////////////////////////////////////////////////////////////////

#define _ARMA_

//(12 Enums)
enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxisy = 2,
	destructno = 0,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class SG_Sounds
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgSoundSets
{
	class VO_Phase1_SoundSet
	{
		soundShaders[] = {"VO_Phase1_SoundShader"};
	};
	class VO_Phase2_SoundSet
	{
		soundShaders[] = {"VO_Phase2_SoundShader"};
	};
	class VO_Phase3_SoundSet
	{
		soundShaders[] = {"VO_Phase3_SoundShader"};
	};
	class VO_Phase_final_SoundSet
	{
		soundShaders[] = {"VO_Phase_final_SoundShader"};
	};
	class VO_FinalPhase_SoundSet
	{
		soundShaders[] = {"VO_FinalPhase_SoundShader"};
	};
	class VO_FencesOff_SoundSet
	{
		soundShaders[] = {"VO_FencesOff_SoundShader"};
	};
	class VO_60min_SoundSet
	{
		soundShaders[] = {"VO_60min_SoundShader"};
	};
	class VO_50min_SoundSet
	{
		soundShaders[] = {"VO_50min_SoundShader"};
	};
	class VO_40min_SoundSet
	{
		soundShaders[] = {"VO_40min_SoundShader"};
	};
	class VO_30min_SoundSet
	{
		soundShaders[] = {"VO_30min_SoundShader"};
	};
	class VO_20min_SoundSet
	{
		soundShaders[] = {"VO_20min_SoundShader"};
	};
	class VO_10min_SoundSet
	{
		soundShaders[] = {"VO_10min_SoundShader"};
	};
	class VO_9min_SoundSet
	{
		soundShaders[] = {"VO_9min_SoundShader"};
	};
	class VO_8min_SoundSet
	{
		soundShaders[] = {"VO_8min_SoundShader"};
	};
	class VO_7min_SoundSet
	{
		soundShaders[] = {"VO_7min_SoundShader"};
	};
	class VO_6min_SoundSet
	{
		soundShaders[] = {"VO_6min_SoundShader"};
	};
	class VO_5min_SoundSet
	{
		soundShaders[] = {"VO_5min_SoundShader"};
	};
	class VO_4min_SoundSet
	{
		soundShaders[] = {"VO_4min_SoundShader"};
	};
	class VO_3min_SoundSet
	{
		soundShaders[] = {"VO_3min_SoundShader"};
	};
	class VO_2min_SoundSet
	{
		soundShaders[] = {"VO_2min_SoundShader"};
	};
	class VO_1min_SoundSet
	{
		soundShaders[] = {"VO_1min_SoundShader"};
	};
	class VO_0min_SoundSet
	{
		soundShaders[] = {"VO_0min_SoundShader"};
	};
	class VO_60sec_SoundSet
	{
		soundShaders[] = {"VO_60sec_SoundShader"};
	};
	class VO_50sec_SoundSet
	{
		soundShaders[] = {"VO_50sec_SoundShader"};
	};
	class VO_40sec_SoundSet
	{
		soundShaders[] = {"VO_40sec_SoundShader"};
	};
	class VO_30sec_SoundSet
	{
		soundShaders[] = {"VO_30sec_SoundShader"};
	};
	class VO_20sec_SoundSet
	{
		soundShaders[] = {"VO_20sec_SoundShader"};
	};
	class VO_10sec_SoundSet
	{
		soundShaders[] = {"VO_10sec_SoundShader"};
	};
	class count_10to01_SoundSet
	{
		soundShaders[] = {"count_10to01_SoundShader"};
	};
	class count_03to01_SoundSet
	{
		soundShaders[] = {"count_03to01_SoundShader"};
	};
	class Collar_Timer01sec_SoundSet
	{
		soundShaders[] = {"Collar_Timer01sec_SoundShader","Collar_Poison_Soundshader"};
	};
	class Collar_Timer10sec_SoundSet
	{
		soundShaders[] = {"Collar_Timer10sec_SoundShader"};
	};
	class Collar_TimerEnd_SoundSet
	{
		soundShaders[] = {"Collar_TimerEnd_SoundShader"};
	};
	class Collar_Explo_SoundSet
	{
		soundShaders[] = {"Collar_Explo_SoundShader"};
	};
	class Collar_ExploST_SoundSet
	{
		soundShaders[] = {"Collar_ExploST_SoundShader"};
	};
	class HeliFly_SoundSet
	{
		soundShaders[] = {"HeliFly_SoundShader"};
	};
	class AirSiren_SoundSet
	{
		soundShaders[] = {"AirSiren_SoundShader"};
		volumeFactor = 1.2;
		volumeCurve = "InverseSquare2Curve";
		sound3DProcessingType = "ExplosionMediumTail3DProcessingType";
		distanceFilter = "explosionTailDistanceFreqAttenuationFilter";
		occlusionFactor = 0.35;
		obstructionFactor = 0.35;
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class Zmb_VoiceFX_Base_SoundSet
	{
		sound3DProcessingType = "character3DProcessingType";
		distanceFilter = "infectedDistanceFreqAttenuationFilter";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
		occlusionFactor = 1;
		obstructionFactor = 1;
		frequencyFactor = 1;
		volumeFactor = 0.75;
	};
	class ZmbM_Normal_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Attack_SoundShader"};
	};
	class ZmbM_Normal_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CallToArmsShort_SoundShader"};
	};
	class ZmbM_Normal_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_HeavyHit_SoundShader"};
	};
	class ZmbM_Normal_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_LightHit_SoundShader"};
	};
	class ZmbM_Normal_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Jump_SoundShader"};
	};
	class ZmbM_Normal_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_Land_SoundShader"};
	};
	class ZmbM_Normal2_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Attack_SoundShader"};
	};
	class ZmbM_Normal2_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CallToArmsShort_SoundShader"};
	};
	class ZmbM_Normal2_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_HeavyHit_SoundShader"};
	};
	class ZmbM_Normal2_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_LightHit_SoundShader"};
	};
	class ZmbM_Normal2_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Jump_SoundShader"};
	};
	class ZmbM_Normal2_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_Land_SoundShader"};
	};
	class ZmbF_Normal_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Attack_SoundShader"};
	};
	class ZmbF_Normal_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CallToArmsShort_SoundShader"};
	};
	class ZmbF_Normal_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_HeavyHit_SoundShader"};
	};
	class ZmbF_Normal_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_LightHit_SoundShader"};
	};
	class ZmbF_Normal_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Jump_SoundShader"};
	};
	class ZmbF_Normal_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Land_SoundShader"};
	};
	class ZmbM_Skinny_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Attack_SoundShader"};
	};
	class ZmbM_Skinny_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CallToArmsShort_SoundShader"};
	};
	class ZmbM_Skinny_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_HeavyHit_SoundShader"};
	};
	class ZmbM_Skinny_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_LightHit_SoundShader"};
	};
	class ZmbM_Skinny_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Jump_SoundShader"};
	};
	class ZmbM_Skinny_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_Land_SoundShader"};
	};
	class ZmbF_Skinny_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Attack_SoundShader"};
	};
	class ZmbF_Skinny_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CallToArmsShort_SoundShader"};
	};
	class ZmbF_Skinny_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_HeavyHit_SoundShader"};
	};
	class ZmbF_Skinny_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_LightHit_SoundShader"};
	};
	class ZmbF_Skinny_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Jump_SoundShader"};
	};
	class ZmbF_Skinny_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Land_SoundShader"};
	};
	class ZmbM_Fat_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_Attack_SoundShader"};
	};
	class ZmbM_Fat_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CallToArmsShort_SoundShader"};
	};
	class ZmbM_Fat_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_HeavyHit_SoundShader"};
	};
	class ZmbM_Fat_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_LightHit_SoundShader"};
	};
	class ZmbM_Fat_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_Jump_SoundShader"};
	};
	class ZmbM_Fat_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_Land_SoundShader"};
	};
	class ZmbF_Fat_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Attack_SoundShader"};
	};
	class ZmbF_Fat_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CallToArmsShort_SoundShader"};
	};
	class ZmbF_Fat_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_HeavyHit_SoundShader"};
	};
	class ZmbF_Fat_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_LightHit_SoundShader"};
	};
	class ZmbF_Fat_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Jump_SoundShader"};
	};
	class ZmbF_Fat_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_Land_SoundShader"};
	};
	class ZmbM_Old_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_Attack_SoundShader"};
	};
	class ZmbM_Old_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CallToArmsShort_SoundShader"};
	};
	class ZmbM_Old_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_HeavyHit_SoundShader"};
	};
	class ZmbM_Old_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_LightHit_SoundShader"};
	};
	class ZmbM_Old_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_Jump_SoundShader"};
	};
	class ZmbM_Old_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_Land_SoundShader"};
	};
	class ZmbF_Old_Attack_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Attack_SoundShader"};
	};
	class ZmbF_Old_CallToArmsShort_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CallToArmsShort_SoundShader"};
	};
	class ZmbF_Old_HeavyHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_HeavyHit_SoundShader"};
	};
	class ZmbF_Old_LightHit_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_LightHit_SoundShader"};
	};
	class ZmbF_Old_Jump_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Jump_SoundShader"};
	};
	class ZmbF_Old_Land_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_Land_SoundShader"};
	};
	class ZmbM_HermitSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_HermitSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_HermitSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_HermitSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_CitizenASkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_CitizenASkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_CitizenASkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_CitizenASkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_PrisonerSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_PrisonerSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_PrisonerSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_PrisonerSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_JournalistSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_JournalistSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_JournalistSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_JournalistSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_HikerSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_HikerSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_HikerSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_HikerSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_JoggerSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_JoggerSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_JoggerSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_JoggerSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_MechanicSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_MechanicSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_MechanicSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_MechanicSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_PatientSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_PatientSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_PatientSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_PatientSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_priestPopSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_CalmMove_SoundShader"};
	};
	class ZmbM_priestPopSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbM_priestPopSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbM_priestPopSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbM_FirefighterNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
	};
	class ZmbM_FirefighterNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbM_FirefighterNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
	};
	class ZmbM_FirefighterNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
	};
	class ZmbM_ParamedicNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
	};
	class ZmbM_ParamedicNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbM_ParamedicNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
	};
	class ZmbM_ParamedicNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
	};
	class ZmbM_SurvivorDean_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
	};
	class ZmbM_SurvivorDean_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbM_SurvivorDean_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
	};
	class ZmbM_SurvivorDean_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
	};
	class ZmbM_PolicemanSpecForce_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
	};
	class ZmbM_PolicemanSpecForce_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbM_PolicemanSpecForce_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
	};
	class ZmbM_PolicemanSpecForce_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
	};
	class ZmbM_SoldierNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
	};
	class ZmbM_SoldierNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbM_SoldierNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
	};
	class ZmbM_SoldierNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
	};
	class ZmbM_usSoldier_normal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
	};
	class ZmbM_usSoldier_normal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbM_usSoldier_normal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
	};
	class ZmbM_usSoldier_normal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
	};
	class ZmbM_PatrolNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_CalmMove_SoundShader"};
	};
	class ZmbM_PatrolNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbM_PatrolNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_AlertedMove_SoundShader"};
	};
	class ZmbM_PatrolNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal_ChaseMove_SoundShader"};
	};
	class ZmbM_SkaterYoung_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
	};
	class ZmbM_SkaterYoung_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
	};
	class ZmbM_SkaterYoung_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
	};
	class ZmbM_SkaterYoung_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
	};
	class ZmbM_ConstrWorkerNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
	};
	class ZmbM_ConstrWorkerNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
	};
	class ZmbM_ConstrWorkerNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
	};
	class ZmbM_ConstrWorkerNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
	};
	class ZmbM_HeavyIndustryWorker_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
	};
	class ZmbM_HeavyIndustryWorker_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
	};
	class ZmbM_HeavyIndustryWorker_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
	};
	class ZmbM_HeavyIndustryWorker_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
	};
	class ZmbM_OffshoreWorker_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
	};
	class ZmbM_OffshoreWorker_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
	};
	class ZmbM_OffshoreWorker_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
	};
	class ZmbM_OffshoreWorker_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
	};
	class ZmbM_HandymanNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
	};
	class ZmbM_HandymanNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
	};
	class ZmbM_HandymanNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
	};
	class ZmbM_HandymanNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
	};
	class ZmbM_Jacket_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
	};
	class ZmbM_Jacket_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
	};
	class ZmbM_Jacket_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
	};
	class ZmbM_Jacket_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
	};
	class ZmbM_Soldier_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_CalmMove_SoundShader"};
	};
	class ZmbM_Soldier_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_DisturbedIdle_SoundShader"};
	};
	class ZmbM_Soldier_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_AlertedMove_SoundShader"};
	};
	class ZmbM_Soldier_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Normal2_ChaseMove_SoundShader"};
	};
	class ZmbM_FarmerFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
	};
	class ZmbM_FarmerFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
	};
	class ZmbM_FarmerFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
	};
	class ZmbM_FarmerFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
	};
	class ZmbM_CitizenBFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
	};
	class ZmbM_CitizenBFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
	};
	class ZmbM_CitizenBFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
	};
	class ZmbM_CitizenBFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
	};
	class ZmbM_PolicemanFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
	};
	class ZmbM_PolicemanFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
	};
	class ZmbM_PolicemanFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
	};
	class ZmbM_PolicemanFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
	};
	class ZmbM_MotobikerFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
	};
	class ZmbM_MotobikerFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
	};
	class ZmbM_MotobikerFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
	};
	class ZmbM_MotobikerFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
	};
	class ZmbM_DoctorFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
	};
	class ZmbM_DoctorFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
	};
	class ZmbM_DoctorFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
	};
	class ZmbM_DoctorFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
	};
	class ZmbM_ClerkFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_CalmMove_SoundShader"};
	};
	class ZmbM_ClerkFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_DisturbedIdle_SoundShader"};
	};
	class ZmbM_ClerkFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_AlertedMove_SoundShader"};
	};
	class ZmbM_ClerkFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Fat_ChaseMove_SoundShader"};
	};
	class ZmbM_VillagerOld_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
	};
	class ZmbM_VillagerOld_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
	};
	class ZmbM_VillagerOld_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
	};
	class ZmbM_VillagerOld_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
	};
	class ZmbM_FishermanOld_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
	};
	class ZmbM_FishermanOld_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
	};
	class ZmbM_FishermanOld_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
	};
	class ZmbM_FishermanOld_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
	};
	class ZmbM_HunterOld_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
	};
	class ZmbM_HunterOld_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
	};
	class ZmbM_HunterOld_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
	};
	class ZmbM_HunterOld_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
	};
	class ZmbM_CommercialPilotOld_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_CalmMove_SoundShader"};
	};
	class ZmbM_CommercialPilotOld_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_DisturbedIdle_SoundShader"};
	};
	class ZmbM_CommercialPilotOld_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_AlertedMove_SoundShader"};
	};
	class ZmbM_CommercialPilotOld_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbM_Old_ChaseMove_SoundShader"};
	};
	class ZmbF_CitizenANormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_CitizenANormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_CitizenANormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_CitizenANormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_JournalistNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_JournalistNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_JournalistNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_JournalistNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_ParamedicNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_ParamedicNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_ParamedicNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_ParamedicNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_SurvivorNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_SurvivorNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_SurvivorNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_SurvivorNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_PoliceWomanNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_PoliceWomanNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_PoliceWomanNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_PoliceWomanNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_MechanicNormal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_MechanicNormal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_MechanicNormal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_MechanicNormal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_Clerk_Normal_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_Clerk_Normal_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_Clerk_Normal_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_Clerk_Normal_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_ShortSkirt_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_ShortSkirt_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_ShortSkirt_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_ShortSkirt_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_CitizenBSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_CitizenBSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_CitizenBSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_CitizenBSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbF_HikerSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_HikerSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_HikerSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_HikerSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbF_JoggerSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_JoggerSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_JoggerSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_JoggerSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbF_SkaterYoung_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_SkaterYoung_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_SkaterYoung_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_SkaterYoung_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbF_DoctorSkinny_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_DoctorSkinny_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_DoctorSkinny_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_DoctorSkinny_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbF_BlueCollarFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_BlueCollarFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_BlueCollarFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_BlueCollarFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_NurseFat_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_CalmMove_SoundShader"};
	};
	class ZmbF_NurseFat_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_DisturbedIdle_SoundShader"};
	};
	class ZmbF_NurseFat_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_AlertedMove_SoundShader"};
	};
	class ZmbF_NurseFat_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Normal_ChaseMove_SoundShader"};
	};
	class ZmbF_PatientOld_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_PatientOld_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_PatientOld_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_PatientOld_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbF_VillagerOld_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_VillagerOld_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_VillagerOld_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_VillagerOld_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class ZmbF_MilkMaidOld_Base_SG_CalmMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_CalmMove_SoundShader"};
	};
	class ZmbF_MilkMaidOld_Base_SG_DisturbedIdle_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_DisturbedIdle_SoundShader"};
	};
	class ZmbF_MilkMaidOld_Base_SG_AlertedMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_AlertedMove_SoundShader"};
	};
	class ZmbF_MilkMaidOld_Base_SG_ChaseMove_Soundset: Zmb_VoiceFX_Base_SoundSet
	{
		soundShaders[] = {"ZmbF_Skinny_ChaseMove_SoundShader"};
	};
	class Zmb_Attack_Light1_Soundset
	{
		soundShaders[] = {"Zmb_Attack_Light1_SoundShader"};
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class Zmb_Attack_Light2_Soundset
	{
		soundShaders[] = {"Zmb_Attack_Light2_SoundShader"};
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class Zmb_Attack_Heavy1_Soundset
	{
		soundShaders[] = {"Zmb_Attack_Heavy1_SoundShader"};
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class Zmb_Attack_Heavy2_Soundset
	{
		soundShaders[] = {"Zmb_Attack_Heavy2_SoundShader"};
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class Zmb_Attack_TwoHands_Soundset
	{
		soundShaders[] = {"Zmb_Attack_TwoHands_SoundShader"};
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "infectedAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
};
class CfgSoundShaders
{
	class AirSiren_Soundshader
	{
		samples[] = {{"\sg\sounds\misc\AirSiren",1}};
		volume = 1.1220185;
		range = 3500;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_Phase1_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_Phase1",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_Phase2_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_Phase2",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_Phase3_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_Phase3",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_Phase_final_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_Phase_final",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_FencesOff_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_Fences_off",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_60min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_60",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_50min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_50",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_40min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_40",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_30min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_30",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_20min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_20",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_10min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_10",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_9min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_09",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_8min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_08",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_7min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_07",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_6min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_06",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_5min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_05",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_4min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_04",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_3min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_03",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_2min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_02",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_1min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_01",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_0min_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_min_00",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_60sec_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_sec_60",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_50sec_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_sec_50",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_40sec_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_sec_40",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_30sec_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_sec_30",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_20sec_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_sec_20",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class VO_10sec_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\vo_sec_10",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class count_10to01_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\count_10to01",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class count_03to01_Soundshader
	{
		samples[] = {{"\sg\sounds\VO\count_03to01",1}};
		volume = 1.0;
		range = 2000;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class Collar_Timer01sec_Soundshader
	{
		samples[] = {{"\sg\sounds\explo\Timer01sec",1}};
		volume = 1.0;
		range = 80;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class Collar_Timer10sec_Soundshader
	{
		samples[] = {{"\sg\sounds\explo\Timer10sec",1}};
		volume = 1.0;
		range = 80;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class Collar_TimerEnd_Soundshader
	{
		samples[] = {{"\sg\sounds\explo\TimerEnd",1}};
		volume = 1.0;
		range = 80;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class Collar_Poison_Soundshader
	{
		samples[] = {{"\sg\sounds\explo\CollarPoison_1",1},{"\sg\sounds\explo\CollarPoison_2",1}};
		volume = 1.0;
		range = 10;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class Collar_Explo_Soundshader
	{
		samples[] = {{"\sg\sounds\explo\CollarExplo",1}};
		volume = 1.0;
		range = 150;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class Collar_ExploST_Soundshader
	{
		samples[] = {{"\sg\sounds\explo\CollarExploST",1}};
		volume = 1.0;
		range = 150;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class HeliFly_Soundshader
	{
		samples[] = {{"\sg\sounds\effects\vehicles\Heli_flying",1}};
		volume = 1.0;
		range = 150;
		rangeCurve = "defaultAmpAttenuationCurve";
	};
	class ZmbM_Skinny_Attack_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Attack_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_HeavyHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_HeavyHit_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_LightHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_LightHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_LightHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_LightHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_LightHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_LightHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_LightHit_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_Jump_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Jump_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Jump_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Jump_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Jump_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Jump_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Jump_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_Land_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Land_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Land_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Land_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Land_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Land_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_Land_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_CallToArmsShort_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CallToArmsShort_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CallToArmsShort_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CallToArmsShort_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CallToArmsShort_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CallToArmsShort_5",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_Attack_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Attack_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Attack_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Attack_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Attack_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Attack_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Attack_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Attack_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_HeavyHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_HeavyHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_HeavyHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_HeavyHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_HeavyHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_HeavyHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_HeavyHit_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_LightHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_LightHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_LightHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_LightHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_LightHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_LightHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_LightHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_LightHit_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_Jump_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Jump_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Jump_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Jump_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Jump_4",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_Land_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Land_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Land_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_Land_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_CallToArmsShort_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CallToArmsShort_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CallToArmsShort_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CallToArmsShort_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_Attack_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_10",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Attack_11",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_HeavyHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_HeavyHit_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_LightHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_LightHit_9",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_Jump_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Jump_9",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_Land_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_Land_9",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_CallToArmsShort_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CallToArmsShort_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CallToArmsShort_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CallToArmsShort_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CallToArmsShort_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CallToArmsShort_5",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_Attack_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Attack_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Attack_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Attack_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Attack_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Attack_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Attack_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_HeavyHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_HeavyHit_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_LightHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_LightHit_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_Jump_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Jump_1",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_Land_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Land_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Land_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_Land_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_CallToArmsShort_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CallToArmsShort_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CallToArmsShort_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CallToArmsShort_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Normal_Attack_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Attack_8",0.125}};
		volume = 0.7;
		range = 60;
	};
	class ZmbF_Normal_HeavyHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_HeavyHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_HeavyHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_HeavyHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_HeavyHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_HeavyHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_HeavyHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_HeavyHit_7",0.125}};
		volume = 0.7;
		range = 60;
	};
	class ZmbF_Normal_LightHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_LightHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_LightHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_LightHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_LightHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_LightHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_LightHit_6",0.125}};
		volume = 0.7;
		range = 60;
	};
	class ZmbF_Normal_Jump_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Jump_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Jump_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Jump_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Jump_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Jump_5",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Normal_Land_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Land_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Land_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Land_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_Land_4",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Normal_CallToArmsShort_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CallToArmsShort_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CallToArmsShort_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CallToArmsShort_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_Attack_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Attack_10",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_HeavyHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_HeavyHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_HeavyHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_HeavyHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_HeavyHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_HeavyHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_HeavyHit_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_LightHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_LightHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_LightHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_LightHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_LightHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_LightHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_LightHit_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_LightHit_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_Jump_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Jump_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Jump_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Jump_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Jump_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Jump_5",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_Land_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Land_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Land_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Land_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Land_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Land_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Land_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_Land_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_CallToArmsShort_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CallToArmsShort_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CallToArmsShort_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CallToArmsShort_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_Attack_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Attack_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_HeavyHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_HeavyHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_HeavyHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_HeavyHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_HeavyHit_4",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_LightHit_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_LightHit_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_LightHit_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_LightHit_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_LightHit_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_LightHit_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_LightHit_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_Jump_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Jump_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Jump_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Jump_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Jump_4",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_Land_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Land_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Land_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_Land_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_CallToArmsShort_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CallToArmsShort_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CallToArmsShort_2",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_CalmMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_10",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_11",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_12",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_13",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_14",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_15",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_16",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_CalmMove_17",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_DisturbedIdle_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_DisturbedIdle_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_DisturbedIdle_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_DisturbedIdle_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_DisturbedIdle_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_DisturbedIdle_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_DisturbedIdle_6",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_AlertedMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_10",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_11",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_12",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_13",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_14",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_15",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_16",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_AlertedMove_17",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Skinny_ChaseMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Skinny_ChaseMove_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_CalmMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CalmMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CalmMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CalmMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CalmMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CalmMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CalmMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_CalmMove_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_DisturbedIdle_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_DisturbedIdle_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_DisturbedIdle_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_DisturbedIdle_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_DisturbedIdle_4",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_AlertedMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_AlertedMove_9",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Skinny_ChaseMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Skinny_ChaseMove_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_CalmMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_10",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_11",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_12",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_13",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_CalmMove_14",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_DisturbedIdle_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_DisturbedIdle_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_DisturbedIdle_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_DisturbedIdle_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_DisturbedIdle_4",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_AlertedMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_10",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_AlertedMove_11",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal_ChaseMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal_ChaseMove_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_CalmMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CalmMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CalmMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CalmMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CalmMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CalmMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CalmMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_CalmMove_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_DisturbedIdle_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_DisturbedIdle_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_DisturbedIdle_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_DisturbedIdle_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_AlertedMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_AlertedMove_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Normal2_ChaseMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_ChaseMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_ChaseMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_ChaseMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_ChaseMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_ChaseMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_ChaseMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Normal2_ChaseMove_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Normal_CalmMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CalmMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CalmMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CalmMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CalmMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CalmMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CalmMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_CalmMove_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Normal_DisturbedIdle_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_DisturbedIdle_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_DisturbedIdle_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_DisturbedIdle_3",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Normal_AlertedMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_AlertedMove_9",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbF_Normal_ChaseMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_ChaseMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_ChaseMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_ChaseMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_ChaseMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_ChaseMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_ChaseMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbF_Normal_ChaseMove_7",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_CalmMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_CalmMove_10",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_DisturbedIdle_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_DisturbedIdle_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_DisturbedIdle_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_DisturbedIdle_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_DisturbedIdle_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_DisturbedIdle_5",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_AlertedMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_AlertedMove_9",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Fat_ChaseMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_9",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_10",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_11",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Fat_ChaseMove_12",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_CalmMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_CalmMove_8",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_DisturbedIdle_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_DisturbedIdle_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_DisturbedIdle_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_DisturbedIdle_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_DisturbedIdle_4",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_AlertedMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_8",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_AlertedMove_9",0.125}};
		volume = 1;
		range = 60;
	};
	class ZmbM_Old_ChaseMove_SoundShader
	{
		samples[] = {{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_1",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_2",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_3",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_4",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_5",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_6",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_7",0.125},{"SG\sounds\ai\infected\VoiceFX\ZmbM_Old_ChaseMove_8",0.125}};
		volume = 1;
		range = 60;
	};
	class Zmb_Attack_Light1_SoundShader
	{
		samples[] = {{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light1_1",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light1_2",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light1_3",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light1_4",0.125}};
		volume = 0.5;
		range = 75;
	};
	class Zmb_Attack_Light2_SoundShader
	{
		samples[] = {{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light2_1",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light2_2",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light2_3",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Light2_4",0.125}};
		volume = 0.5;
		range = 75;
	};
	class Zmb_Attack_Heavy1_SoundShader
	{
		samples[] = {{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy1_1",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy1_2",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy1_3",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy1_4",0.125}};
		volume = 0.5;
		range = 75;
	};
	class Zmb_Attack_Heavy2_SoundShader
	{
		samples[] = {{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy2_1",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy2_2",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy2_3",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_Heavy2_4",0.125}};
		volume = 0.5;
		range = 75;
	};
	class Zmb_Attack_TwoHands_SoundShader
	{
		samples[] = {{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_TwoHands_1",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_TwoHands_2",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_TwoHands_3",0.125},{"DZ\sounds\ai\infected\AttackFoley\Zmb_Attack_TwoHands_4",0.125}};
		volume = 0.6;
		range = 75;
	};
};
