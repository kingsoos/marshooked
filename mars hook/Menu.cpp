#include "Menu.h"
#include "Controls.h"
#include "Hooks.h" 
#include "Interfaces.h"
#include "CRC32.h"

#define WINDOW_WIDTH 635
#define WINDOW_HEIGHT 510

aristoispejawindow g_menu::window;

void KnifeApplyCallbk()
{
	static ConVar* Meme = Interfaces::CVar->FindVar("cl_fullupdate");
	Meme->nFlags &= ~FCVAR_CHEAT;
	Interfaces::Engine->ClientCmd_Unrestricted("cl_fullupdate");
}

void SaveLegitCallbk()
{
	switch (g_menu::window.MiscTab.lstPlayers.GetIndex())
	{
	case 0:GUI.SaveWindowState(&g_menu::window, "1.cfg"); break;
	case 1:GUI.SaveWindowState(&g_menu::window, "2.cfg"); break;
	case 2:GUI.SaveWindowState(&g_menu::window, "3.cfg"); break;
	case 3:GUI.SaveWindowState(&g_menu::window, "4.cfg"); break;
	case 4:GUI.SaveWindowState(&g_menu::window, "5.cfg"); break;
	case 5:GUI.SaveWindowState(&g_menu::window, "6.cfg"); break;
	}
}

void LoadLegitCallbk()
{
	static ConVar* Meme = Interfaces::CVar->FindVar("cl_fullupdate");
	Interfaces::Engine->ClientCmd_Unrestricted("cl_fullupdate");
	switch (g_menu::window.MiscTab.lstPlayers.GetIndex())
	{
	case 0:GUI.LoadWindowState(&g_menu::window, "1.cfg"); break;	
	case 1:GUI.LoadWindowState(&g_menu::window, "2.cfg"); break;	
	case 2:GUI.LoadWindowState(&g_menu::window, "3.cfg"); break;	
	case 3:GUI.LoadWindowState(&g_menu::window, "4.cfg"); break;
	case 4:GUI.LoadWindowState(&g_menu::window, "5.cfg"); break;
	case 5:GUI.LoadWindowState(&g_menu::window, "6.cfg"); break;
	}
}


void UnLoadCallbk()
{
	DoUnload = true;
}

void aristoispejawindow::Setup()
{
	SetPosition(350, 50);
	SetSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	SetTitle("MarsCheat fixed by d e w#6840");

	RegisterTab(&RageBotTab);
	RegisterTab(&AntiAimtab);
	RegisterTab(&LegitbotTab);
	RegisterTab(&VisualsTab);
	RegisterTab(&Movetab);
	RegisterTab(&ColorsTab);
    RegisterTab(&Skins);
	RegisterTab(&SettingsTab);
	RegisterTab(&MiscTab);

	RECT Client = GetClientArea();
	Client.bottom -= 29;

	RageBotTab.Setup();
	AntiAimtab.Setup();
	LegitbotTab.Setup();
	VisualsTab.Setup();
	Movetab.Setup();
	Skins.Setup();
	ColorsTab.Setup();
	SettingsTab.Setup();
	MiscTab.Setup();
	
#pragma endregion Setting up the settings buttons
}

void CRageBotTab::Setup()
{
	SetTitle("Rage");

	AimbotGroup.SetPosition(150, -50);
	AimbotGroup.SetText("Aimbot");
	AimbotGroup.SetSize(220, 250);
	RegisterControl(&AimbotGroup);

	AimbotEnable.SetFileId("aim_enable");
	AimbotGroup.PlaceLabledControl("Enable", this, &AimbotEnable);

	AimbotAutoFire.SetFileId("aim_autofire");
	AimbotGroup.PlaceLabledControl("Auto fire", this, &AimbotAutoFire);

	AimbotFov2.SetFileId("aim_fov2");
	AimbotGroup.PlaceLabledControl("FOV Range", this, &AimbotFov2);

	AimbotFov.SetFileId("aim_fov");
	AimbotFov.SetBoundaries(0.f, 180.f);
	AimbotFov.SetValue(39.f);
	AimbotGroup.PlaceLabledControl("", this, &AimbotFov);

	AimbotSilentAim.SetFileId("aim_silent");
	AimbotGroup.PlaceLabledControl("Silent aim", this, &AimbotSilentAim);

	AutoRevolver.SetFileId("aim_autorevolver");
	AimbotGroup.PlaceLabledControl("Auto revolver", this, &AutoRevolver);

	Nadaaa.SetFileId("aim_gggggggg");
	AimbotGroup.PlaceLabledControl("Override", this, &Nadaaa);

	SomeShit.SetFileId("aim_naosei");
	AimbotGroup.PlaceLabledControl("", this, &SomeShit);
		
	AccuracyAutoScope.SetFileId("auto_scoped");
	AimbotGroup.PlaceLabledControl("Auto scope", this, &AccuracyAutoScope);

	AutoMinimumDamage.SetFileId("aim_autodamage");
	AimbotGroup.PlaceLabledControl("Auto damage", this, &AutoMinimumDamage);

	AutoHitChance.SetFileId("aim_autohitchance");
	AimbotGroup.PlaceLabledControl("Auto Hit chance", this, &AutoHitChance);

	hitchance2.SetFileId("aim_autohitchance2");
	AimbotGroup.PlaceLabledControl("Hit chance", this, &hitchance2);

	AccuracyHitchance.SetFileId("hit_chance");
	AccuracyHitchance.SetBoundaries(0, 100);
	AccuracyHitchance.SetValue(0);
	AimbotGroup.PlaceLabledControl("", this, &AccuracyHitchance);

	mindamage2.SetFileId("aim_autodamage2");
	AimbotGroup.PlaceLabledControl("Minimun damage", this, &mindamage2);

	AccuracyMinimumDamage.SetFileId("minimum_dmg");
	AccuracyMinimumDamage.SetBoundaries(0, 100);
	AccuracyMinimumDamage.SetValue(0);
	AimbotGroup.PlaceLabledControl("", this, &AccuracyMinimumDamage);

#pragma endregion Aimbot Controls Get Setup in here

	Hitbox.SetPosition(200, 410);
	Hitbox.SetText("hitscan head");
	Hitbox.SetSize(220, 250);
	RegisterControl(&Hitbox);

	Hitboxhead.SetFileId("aim_head");
	Hitbox.PlaceLabledControl("Head", this, &Hitboxhead);

	Hitbox2.SetPosition(265, 410);
	Hitbox2.SetText("hitscan neck");
	Hitbox2.SetSize(220, 250);
	RegisterControl(&Hitbox2);

	Hitboxneck.SetFileId("aim_neck");
	Hitbox2.PlaceLabledControl("Neck", this, &Hitboxneck);

	Hitbox3.SetPosition(328, 410);
	Hitbox3.SetText("hitscan arms");
	Hitbox3.SetSize(220, 250);
	RegisterControl(&Hitbox3);

	Hitboxarms.SetFileId("aim_chest");
	Hitbox3.PlaceLabledControl("Arms", this, &Hitboxarms);

	Hitbox4.SetPosition(386, 410);
	Hitbox4.SetText("hitscan chest");
	Hitbox4.SetSize(220, 250);
	RegisterControl(&Hitbox4);

	Hitboxchest.SetFileId("aim_chest");
	Hitbox4.PlaceLabledControl("Chest", this, &Hitboxchest);

	Hitbox5.SetPosition(447, 410);
	Hitbox5.SetText("hitscan legs");
	Hitbox5.SetSize(220, 250);
	RegisterControl(&Hitbox5);

	Hitboxlegs.SetFileId("aim_legs");
	Hitbox5.PlaceLabledControl("Legs", this, &Hitboxlegs);
#pragma region AntiAim
	AntiAimGroup.SetPosition(375, -50);
	AntiAimGroup.SetText("Accuracy");
	AntiAimGroup.SetSize(220, 250);
	RegisterControl(&AntiAimGroup);

	AimbotResolver2.SetFileId("aim_resolver");
	AntiAimGroup.PlaceLabledControl("Resolver", this, &AimbotResolver2);

	AimbotResolver.SetFileId("acc_resolver");
	AimbotResolver.AddItem("None");
	AimbotResolver.AddItem("Matchmaking");
	AntiAimGroup.PlaceLabledControl("", this, &AimbotResolver);

	TargetSelection2.SetFileId("aim_target2");
	AntiAimGroup.PlaceLabledControl("Target selection", this, &TargetSelection2);

	TargetSelection.SetFileId("tgt_selection");
	TargetSelection.AddItem("FOV");
	TargetSelection.AddItem("Far away");
	TargetSelection.AddItem("Lethal");
	TargetSelection.AddItem("Threat");
	TargetSelection.AddItem("2 shot");
	AntiAimGroup.PlaceLabledControl("", this, &TargetSelection);

	Resolverfakewalk.SetFileId("acc_fakewalkfix");
	AntiAimGroup.PlaceLabledControl("Anim fix", this, &Resolverfakewalk);

	AccuracyResolverbrute.SetFileId("acc_resolverpitch");
	AntiAimGroup.PlaceLabledControl("Pitch correct", this, &AccuracyResolverbrute);

	EnginePrediction.SetFileId("acc_engineprediciton");
	AntiAimGroup.PlaceLabledControl("Engine predict", this, &EnginePrediction);

	AccuracyRecoil.SetFileId("acc_norecoil");
	AntiAimGroup.PlaceLabledControl("Compescale recoil", this, &AccuracyRecoil);

	AccuracyAutoWall.SetFileId("acc_awall");
	AntiAimGroup.PlaceLabledControl("Penetrate walls", this, &AccuracyAutoWall);

	AccuracyBacktracking.SetFileId("acc_bcktrk");
	AntiAimGroup.PlaceLabledControl("BackTrack", this, &AccuracyBacktracking);

	TargetMultipoint.SetFileId("acc_multipoint");
	AntiAimGroup.PlaceLabledControl("Multi-point", this, &TargetMultipoint);

	TargetPointscale2.SetFileId("acc_pt2");
	AntiAimGroup.PlaceLabledControl("Point scale", this, &TargetPointscale2);

	TargetPointscale.SetFileId("pointscale");
	TargetPointscale.SetBoundaries(0, 10);
	AntiAimGroup.PlaceLabledControl("", this, &TargetPointscale);

	BaimIfUnderXHealth2.SetFileId("acc_baim2");
	AntiAimGroup.PlaceLabledControl("B-AIM if hp", this, &BaimIfUnderXHealth2);

	BaimIfUnderXHealth.SetFileId("baimifhp");
	BaimIfUnderXHealth.SetBoundaries(0, 100);
	BaimIfUnderXHealth.SetValue(0);
	AntiAimGroup.PlaceLabledControl("", this, &BaimIfUnderXHealth);


#pragma endregion  AntiAim controls get setup in here
}

void CLegitBot::Setup()
{
	SetTitle("Legit");

	AimbotGroup.SetPosition(150, -50);
	AimbotGroup.SetText("Aimbot");
	AimbotGroup.SetSize(220, 250);
	RegisterControl(&AimbotGroup);

	AimbotEnable.SetFileId("aim_enable");
	AimbotGroup.PlaceLabledControl("Enable", this, &AimbotEnable);

	AccuracyBacktracking.SetFileId("accuracybacktracking");
	AimbotGroup.PlaceLabledControl("Backtrack", this, &AccuracyBacktracking);
}


void CAntiAimtab::Setup()
{
	SetTitle("Anti-Aim");

	Antiaim.SetPosition(150, -50);
	Antiaim.SetText("anti-aim");
	Antiaim.SetSize(220, 250);
	RegisterControl(&Antiaim);

	AntiAimEnable.SetFileId("aa_enable");
	Antiaim.PlaceLabledControl("Enable", this, &AntiAimEnable);

	inair2.SetFileId("inair_aa");
	Antiaim.PlaceLabledControl("Edge", this, &inair2);

	InAir.SetFileId("inair");
	InAir.AddItem("Stand");
	InAir.AddItem("Half spin");
	InAir.AddItem("Backwards");
	Antiaim.PlaceLabledControl("", this, &InAir);

	pitch2.SetFileId("pitch_aa");
	Antiaim.PlaceLabledControl("Pitch", this, &pitch2);

	AntiAimPitch.SetFileId("aa_x");
	AntiAimPitch.AddItem("None");
	AntiAimPitch.AddItem("Emotion");
	AntiAimPitch.AddItem("Minimal");
	AntiAimPitch.AddItem("Dynamic");
	AntiAimPitch.AddItem("Jitter");
	Antiaim.PlaceLabledControl("", this, &AntiAimPitch);

	realyaw2.SetFileId("realyaw_aa");
	Antiaim.PlaceLabledControl("Yaw", this, &realyaw2);

	AntiAimYaw.SetFileId("aa_y");
	AntiAimYaw.AddItem("None");
	AntiAimYaw.AddItem("Backwards");
	AntiAimYaw.AddItem("Jitter");
	AntiAimYaw.AddItem("Lowerbody");
	AntiAimYaw.AddItem("Dynamic Swap");
	AntiAimYaw.AddItem("Fast Spin");
	AntiAimYaw.AddItem("Auto");
	AntiAimYaw.AddItem("Manual");
	Antiaim.PlaceLabledControl("", this, &AntiAimYaw);

	SWSwitchEnable.SetFileId("manualaa");
	Antiaim.PlaceLabledControl("Switch", this, &SWSwitchEnable);

	SWSwitchKey.SetFileId("swswitchkey");
	SWSwitchKey.SetKey(88);
	Antiaim.PlaceLabledControl("", this, &SWSwitchKey);

	lbydelta.SetFileId("lby_aa");
	Antiaim.PlaceLabledControl("LBY", this, &lbydelta);

	BreakLBY.SetFileId("aa_break");
	BreakLBY.AddItem("None");
	/* BreakLBY.AddItem("Custom°"); */ // Не вижу смысла в этой функции, пока здесь ничего не работает/I do not see the point in this function, until nothing works here
	BreakLBY.AddItem("135°");
	/* BreakLBY.AddItem("Cooming Soon°"); */ // Не вижу смысла в этой функции, пока здесь ничего не работает/I do not see the point in this function, until nothing works here
	Antiaim.PlaceLabledControl("", this, &BreakLBY);

	Antilby.SetFileId("antilby");
	Antilby.SetBoundaries(0, 180);
	Antilby.SetValue(95);
	Antiaim.PlaceLabledControl("", this, &Antilby);

	AntiAim2.SetPosition(375, -50);
	AntiAim2.SetText("fakeyaw");
	AntiAim2.SetSize(220, 250);
	RegisterControl(&AntiAim2);

	fakeyaw2.SetFileId("fakeyaw_aa");
	AntiAim2.PlaceLabledControl("Fake yaw", this, &fakeyaw2);

	FakeYaw.SetFileId("fakeaa");
	FakeYaw.AddItem("None");
	FakeYaw.AddItem("180 Jitter");
	FakeYaw.AddItem("180 LBY");
	FakeYaw.AddItem("LBY Jitter");
	FakeYaw.AddItem("Free");
	FakeYaw.AddItem("Spin");
	AntiAim2.PlaceLabledControl("", this, &FakeYaw);

	fakelag25.SetFileId("aa_fakelag4");
	AntiAim2.PlaceLabledControl("Fake-Lag", this, &fakelag25);

	fakelag23.SetFileId("aa_fakelag2");
	fakelag23.AddItem("None");
	fakelag23.AddItem("Maximum");
	AntiAim2.PlaceLabledControl("", this, &fakelag23);

	fakelag24.SetFileId("aa_fakelag3");
	fakelag24.AddItem("Max");
	AntiAim2.PlaceLabledControl("", this, &fakelag24);

	fakelag2.SetFileId("fakelag2");
	AntiAim2.PlaceLabledControl("Limit", this, &fakelag2);

	fakelagvalue2.SetFileId("fakelag3");
	fakelagvalue2.SetBoundaries(0.f, 20.f);
	fakelagvalue2.SetValue(0.f);
	AntiAim2.PlaceLabledControl("", this, &fakelagvalue2);

	onlands.SetFileId("on-land");
	AntiAim2.PlaceLabledControl("On land", this, &onlands);

	separado2.SetFileId("separado");
	AntiAim2.PlaceLabledControl("", this, &separado2);
	
}                                                                  

void CVisualTab::Setup()
{
	SetTitle("players");

	OptionsGroup.SetPosition(150, -50);
	OptionsGroup.SetText("options");
	OptionsGroup.SetSize(220, 250);
	RegisterControl(&OptionsGroup);

	FiltersEnemiesOnly.SetFileId("ftr_enemyonly");
	OptionsGroup.PlaceLabledControl("Enemies Only", this, &FiltersEnemiesOnly);

	boxx22.SetFileId("otp_seperatebox");
	OptionsGroup.PlaceLabledControl("Box", this, &boxx22);

	OptionsBox.SetFileId("otr_showbox");
	OptionsBox.AddItem("None");
	/* OptionsBox.AddItem("custom"); */ // Не вижу смысла в этой функции, пока здесь ничего не работает/I do not see the point in this function, until nothing works here
	OptionsBox.AddItem("Normal");
	OptionsGroup.PlaceLabledControl("", this, &OptionsBox);

	chams33.SetFileId("otp_seperetachams");
	OptionsGroup.PlaceLabledControl("Chams", this, &chams33);

	OptionsChams.SetFileId("esp_chams");
	OptionsChams.AddItem("None");
	OptionsChams.AddItem("3D");
	OptionsChams.AddItem("2D");
	OptionsGroup.PlaceLabledControl("", this, &OptionsChams);

	OptionsGlow.SetFileId("otp_glow");
	OptionsGroup.PlaceLabledControl("Glow", this, &OptionsGlow);

	OptionsName.SetFileId("opt_name");
	OptionsGroup.PlaceLabledControl("Name", this, &OptionsName);

	OptionsWeapon.SetFileId("opt_weapon");
	OptionsGroup.PlaceLabledControl("Weapon", this, &OptionsWeapon);

	OptionHealthEnable.SetFileId("opt_health");
	OptionsGroup.PlaceLabledControl("Health", this, &OptionHealthEnable);

	//OptionsArmor.SetFileId("opt_armor");
	//OptionsGroup.PlaceLabledControl("armor", this, &OptionsArmor);

	OptionsSkeleton.SetFileId("opt_bone");
	OptionsGroup.PlaceLabledControl("Skeleton", this, &OptionsSkeleton);

	cl_righthandse.SetFileId("cl_righthand");
	OptionsGroup.PlaceLabledControl("", this, &cl_righthandse);
	
	OptionsInfo.SetFileId("opt_info");
	OptionsGroup.PlaceLabledControl("Info", this, &OptionsInfo);

	FiltersC4.SetFileId("bomb");
	OptionsGroup.PlaceLabledControl("C4", this, &FiltersC4);

	FiltersWeapons.SetFileId("ftr_weaponss");
	OptionsGroup.PlaceLabledControl("Weapons", this, &FiltersWeapons);

	OtherNoScope.SetFileId("eff_noscope");
	OptionsGroup.PlaceLabledControl("No scope", this, &OtherNoScope);

	OtherNoVisualRecoil.SetFileId("eff_visrecoil");
	OptionsGroup.PlaceLabledControl("No visual recoil", this, &OtherNoVisualRecoil);

	OtherNoFlash.SetFileId("otr_noflash");
	OptionsGroup.PlaceLabledControl("No flash ", this, &OtherNoFlash);

	OtherNoSmoke.SetFileId("eff_nosmoke");
	OptionsGroup.PlaceLabledControl("No smoke", this, &OtherNoSmoke);

	ESPOther.SetPosition(375, -50);
	ESPOther.SetText("Accuracy");
	ESPOther.SetSize(220, 250);
	RegisterControl(&ESPOther);

	ManualaaIndicator.SetFileId("opt_aaindicaor");
	ESPOther.PlaceLabledControl("AA Indicator", this, &ManualaaIndicator);

	LBYIdicador.SetFileId("opt_indicaor");
	ESPOther.PlaceLabledControl("LBY Indicator", this, &LBYIdicador);

	BulletTracers.SetFileId("bullettracers");
	ESPOther.PlaceLabledControl("Bullet tracers", this, &BulletTracers);

	DamageIndicator.SetFileId("damageindicator");
	ESPOther.PlaceLabledControl("Show damage", this, &DamageIndicator);

	SpreadCrosshair.SetFileId("spreadcrosshair");
	ESPOther.PlaceLabledControl("Spread crosshair", this, &SpreadCrosshair);

	spreadslider.SetFileId("otr_spreadslider");
	spreadslider.SetBoundaries(0.f, 255.f);
	spreadslider.SetValue(89.f);
	ESPOther.PlaceLabledControl("", this, &spreadslider);

	SpecList.SetFileId("otr_speclist");
	ESPOther.PlaceLabledControl("Show spectators", this, &SpecList);

	handdd22.SetFileId("otr_seperatehand");
	ESPOther.PlaceLabledControl("Hands", this, &handdd22);

	OtherNoHands.SetFileId("otr_hands");
	OtherNoHands.AddItem("None");
	OtherNoHands.AddItem("Glass");
	OtherNoHands.AddItem("Transparent");
	OtherNoHands.AddItem("Wireframe");
	ESPOther.PlaceLabledControl("", this, &OtherNoHands);

	OtherCrosshair.SetFileId("otr_rsrinfo");
	ESPOther.PlaceLabledControl("Wallbang damage", this, &OtherCrosshair);

	NightMode.SetFileId("nightmode");
	ESPOther.PlaceLabledControl("Night mode", this, &NightMode);

	DisablePostProcess.SetFileId("otr_disablepostprocess");
	ESPOther.PlaceLabledControl("Disable Post Process", this, &DisablePostProcess);

//	offscreen.SetFileId("offscreen");
//	ESPOther.PlaceLabledControl("offscreen", this, &offscreen);

	f2.SetFileId("fieldofview");
	ESPOther.PlaceLabledControl("Field of view", this, &f2);

	OtherFOV.SetFileId("otr_fov");
	OtherFOV.SetBoundaries(0.f, 180.f);
	OtherFOV.SetValue(0.f);
	ESPOther.PlaceLabledControl("", this, &OtherFOV);
	
	FiltersPlayers.SetState(true);
	FiltersC4.SetState(true);
#pragma endregion Setting up the Options controls
}


void CColorTab::Setup()
{
	SetTitle("visuals");
#pragma region Visual Colors


	Colors.SetPosition(150, -50);
	Colors.SetText("Colors");
	Colors.SetSize(220, 250);
	RegisterControl(&Colors);
	
	a17.SetFileId("boxchecker");
	Colors.PlaceLabledControl("- Box color", this, &a17);

	a14.SetFileId("boxcheckerx");
	Colors.PlaceLabledControl("", this, &a14);

	a1.SetFileId("otr_cricleb0000utton");
	Colors.PlaceLabledControl("Visible red", this, &a1);
	
	CTColorVisR.SetFileId("ct_color_vis_r");
	CTColorVisR.SetBoundaries(0.f, 255.f);
	CTColorVisR.SetValue(0.f);
	Colors.PlaceLabledControl("", this, &CTColorVisR);

	a2.SetFileId("otr_cric4444lebutton");
	Colors.PlaceLabledControl("Visible green", this, &a2);

	CTColorVisG.SetFileId("ct_color_vis_g");
	CTColorVisG.SetBoundaries(0.f, 255.f);
	CTColorVisG.SetValue(230.f);
	Colors.PlaceLabledControl("", this, &CTColorVisG);

	a3.SetFileId("otr_criclebutt21321on");
	Colors.PlaceLabledControl("Visible blue", this, &a3);


	a31.SetFileId("seperate3");
	Colors.PlaceLabledControl("", this, &a31);


	CTColorVisB.SetFileId("ct_color_vis_b");
	CTColorVisB.SetBoundaries(0.f, 255.f);
	CTColorVisB.SetValue(15.f);
	Colors.PlaceLabledControl("", this, &CTColorVisB);

	a4.SetFileId("otr_criclebu321tton");
	Colors.PlaceLabledControl("Not visible red", this, &a4);


	CTColorNoVisR.SetFileId("ct_color_no_vis_r");
	CTColorNoVisR.SetBoundaries(0.f, 255.f);
	CTColorNoVisR.SetValue(0.f);
	Colors.PlaceLabledControl("", this, &CTColorNoVisR);

	a5.SetFileId("otr_cricleb000utton");
	Colors.PlaceLabledControl("Not visible green", this, &a5);

	CTColorNoVisG.SetFileId("ct_color_no_vis_g");
	CTColorNoVisG.SetBoundaries(0.f, 255.f);
	CTColorNoVisG.SetValue(235.f);
	Colors.PlaceLabledControl("", this, &CTColorNoVisG);

	a6.SetFileId("otr_criclebut1111ton");
	Colors.PlaceLabledControl("Not visible blue", this, &a6);

	CTColorNoVisB.SetFileId("ct_color_no_vis_b");
	CTColorNoVisB.SetBoundaries(0.f, 255.f);
	CTColorNoVisB.SetValue(10.f);
	Colors.PlaceLabledControl("", this, &CTColorNoVisB);


	a30.SetFileId("seperate4");
	Colors.PlaceLabledControl("", this, &a30);


	a7.SetFileId("otr_cricle90button");
	Colors.PlaceLabledControl("Visible red", this, &a7);


	TColorVisR.SetFileId("t_color_vis_r");
	TColorVisR.SetBoundaries(0.f, 255.f);
	TColorVisR.SetValue(0.f);
	Colors.PlaceLabledControl("", this, &TColorVisR);

	a8.SetFileId("otr_criclebu77tton");
	Colors.PlaceLabledControl("Visible green", this, &a8);

	TColorVisG.SetFileId("t_color_vis_g");
	TColorVisG.SetBoundaries(0.f, 255.f);
	TColorVisG.SetValue(50.f);
	Colors.PlaceLabledControl("", this, &TColorVisG);

	a9.SetFileId("otr_criclebut55ton");
	Colors.PlaceLabledControl("Visible blue", this, &a10);

	TColorVisB.SetFileId("t_color_vis_b");
	TColorVisB.SetBoundaries(0.f, 255.f);
	TColorVisB.SetValue(220.f);
	Colors.PlaceLabledControl("", this, &TColorVisB);


	a28.SetFileId("seperate5");
	Colors.PlaceLabledControl("", this, &a28);


	a11.SetFileId("otr_cricle66button");
	Colors.PlaceLabledControl("Not visible red", this, &a11);

	TColorNoVisR.SetFileId("t_color_no_vis_r");
	TColorNoVisR.SetBoundaries(0.f, 255.f);
	TColorNoVisR.SetValue(0.f);
	Colors.PlaceLabledControl("", this, &TColorNoVisR);

	a12.SetFileId("otr_criclebutton");
	Colors.PlaceLabledControl("Not visible green", this, &a12);

	TColorNoVisG.SetFileId("t_color_no_vis_g");
	TColorNoVisG.SetBoundaries(0.f, 255.f);
	TColorNoVisG.SetValue(50.f);
	Colors.PlaceLabledControl("", this, &TColorNoVisG);

	a13.SetFileId("otr_criclebu77tton");
	Colors.PlaceLabledControl("Not visible blue", this, &a13);

	TColorNoVisB.SetFileId("t_color_no_vis_b");
	TColorNoVisB.SetBoundaries(0.f, 255.f);
	TColorNoVisB.SetValue(220.f);
	Colors.PlaceLabledControl("", this, &TColorNoVisB);

	Colors2.SetPosition(375, -50);
	Colors2.SetText("others");
	Colors2.SetSize(220, 250);
	RegisterControl(&Colors2);

	a19.SetFileId("glowchecker");
	Colors2.PlaceLabledControl("- Glow", this, &a19);

	a16.SetFileId("glowcheckerx");
	Colors2.PlaceLabledControl("", this, &a16);

	a20.SetFileId("otr_cricleb5utton");
	Colors2.PlaceLabledControl("Red", this, &a20);

	GlowR.SetFileId("GlowR");
	GlowR.SetBoundaries(0.f, 255.f);
	GlowR.SetValue(230.f);
	Colors2.PlaceLabledControl("", this, &GlowR);

	a21.SetFileId("otr_criclebu7tton");
	Colors2.PlaceLabledControl("Green", this, &a21);

	GlowG.SetFileId("GlowG");
	GlowG.SetBoundaries(0.f, 255.f);
	GlowG.SetValue(0.f);
	Colors2.PlaceLabledControl("", this, &GlowG);

	a22.SetFileId("otr_criclebutton");
	Colors2.PlaceLabledControl("Blue", this, &a22);

	GlowB.SetFileId("GlowB");
	GlowB.SetBoundaries(0.f, 255.f);
	GlowB.SetValue(0.f);
	Colors2.PlaceLabledControl("", this, &GlowB);

	a33.SetFileId("seperate1");
	Colors2.PlaceLabledControl("", this, &a33);

	a18.SetFileId("bullettracechecker");
	Colors2.PlaceLabledControl("- Bullet trace", this, &a18);

	a15.SetFileId("bullettracecheckerx");
	Colors2.PlaceLabledControl("", this, &a15);

	a29.SetFileId("otr_criclebutto5n");
	Colors2.PlaceLabledControl("CT Red", this, &a29);

	BULLETCT_R.SetFileId("bulletctR");
	BULLETCT_R.SetBoundaries(0.f, 255.f);
	BULLETCT_R.SetValue(0.f);
	Colors2.PlaceLabledControl("", this, &BULLETCT_R);

	a23.SetFileId("otr_criclebutto4n");
	Colors2.PlaceLabledControl("CT Green", this, &a23);

	BULLETCT_G.SetFileId("bulletctG");
	BULLETCT_G.SetBoundaries(0.f, 255.f);
	BULLETCT_G.SetValue(0.f);
	Colors2.PlaceLabledControl("", this, &BULLETCT_G);

	a24.SetFileId("otr_criclebutton4");
	Colors2.PlaceLabledControl("CT Blue", this, &a24);

	BULLETCT_B.SetFileId("bulletctB");
	BULLETCT_B.SetBoundaries(0.f, 255.f);
	BULLETCT_B.SetValue(0.f);
	Colors2.PlaceLabledControl("", this, &BULLETCT_B);

	a32.SetFileId("seperate2");
	Colors2.PlaceLabledControl("", this, &a32);

	a25.SetFileId("otr_criclebutton3");
	Colors2.PlaceLabledControl("T Red", this, &a25);

	BULLET_T_R.SetFileId("bullettR");
	BULLET_T_R.SetBoundaries(0.f, 255.f);
	BULLET_T_R.SetValue(230.f);
	Colors2.PlaceLabledControl("", this, &BULLET_T_R);

	a26.SetFileId("otr_criclebutton2");
	Colors2.PlaceLabledControl("T Green", this, &a26);

	BULLET_T_G.SetFileId("bullettG");
	BULLET_T_G.SetBoundaries(0.f, 255.f);
	BULLET_T_G.SetValue(0.f);
	Colors2.PlaceLabledControl("", this, &BULLET_T_G);

	a27.SetFileId("otr_criclebutton1");
	Colors2.PlaceLabledControl("T Blue", this, &a27);

	BULLET_T_B.SetFileId("bullettB");
	BULLET_T_B.SetBoundaries(0.f, 255.f);
	BULLET_T_B.SetValue(0.f);
	Colors2.PlaceLabledControl("", this, &BULLET_T_B);
#pragma endregion
}

void Movement::Setup()
{
	SetTitle("moviment");

	Movetab.SetPosition(150, -50);
	Movetab.SetText("other");
	Movetab.SetSize(220, 250);
	RegisterControl(&Movetab);

	OtherAutoJump.SetFileId("otr_autojump");
	Movetab.PlaceLabledControl("AutoBhop", this, &OtherAutoJump);

	OtherAutoStrafe.SetFileId("otr_strafe");
	Movetab.PlaceLabledControl("AutoStrafe", this, &OtherAutoStrafe);

	OtherCircle.SetFileId("otr_criclebutton");
	Movetab.PlaceLabledControl("Circle Strafe", this, &OtherCircle);

}

 void SkinsTab::Setup() 
{
	SetTitle("skins");
} 

void CSettingsTab::Setup()
{
    SetTitle("misc");

    MiscGroup.SetPosition(150, -50);
    MiscGroup.SetText("other");
    MiscGroup.SetSize(220, 250);
    RegisterControl(&MiscGroup);

	autobuy.SetFileId("auto_buy");
	MiscGroup.PlaceLabledControl("Auto Buy Items", this, &autobuy);

	BuyBot.SetFileId("aut_buyweapon");
	BuyBot.AddItem("None");
	BuyBot.AddItem("SSG08");
	BuyBot.AddItem("SCAR20");
	BuyBot.AddItem("Negev");
	MiscGroup.PlaceLabledControl("", this, &BuyBot);

	BuyBotPistol.SetFileId("aut_buyweaponpistol");
	BuyBotPistol.AddItem("none");
	BuyBotPistol.AddItem("Berettas");
	BuyBotPistol.AddItem("Revolver");
	MiscGroup.PlaceLabledControl("", this, &BuyBotPistol);

	BuyBotGrenades.SetFileId("aut_buyweaponzeus");
	BuyBotGrenades.AddItem("None");
	BuyBotGrenades.AddItem("Zeus + Kit Grenades");
	BuyBotGrenades.AddItem("Zeus + Defuser + Kit Grenades");
	MiscGroup.PlaceLabledControl("", this, &BuyBotGrenades);

	Logs2.SetFileId("auto_nofications");
	MiscGroup.PlaceLabledControl("Notifications", this, &Logs2);

	Logs.SetFileId("auto_noficaitins");
	Logs.AddItem("None");
	Logs.AddItem("On");
	MiscGroup.PlaceLabledControl("", this, &Logs);

	FakePingExploit.SetFileId("otr_fakepingexploit");
	MiscGroup.PlaceLabledControl("Fake latency nosafe*", this, &FakePingExploit);

	FakePingValue.SetFileId("auto_fakelatencyslider");
	FakePingValue.SetBoundaries(0.f, 800.f);
	FakePingValue.SetValue(0.f);
	MiscGroup.PlaceLabledControl("", this, &FakePingValue);

	//other tab 2 in supremacy

	misctabzin2.SetPosition(375, -50);
	misctabzin2.SetText("others");
	misctabzin2.SetSize(220, 250);
	RegisterControl(&misctabzin2);

	AutoAccept.SetFileId("auto_accept");
	misctabzin2.PlaceLabledControl("Autoaccept Matchmaking", this, &AutoAccept);

	m2.SetFileId("auto_2");
	misctabzin2.PlaceLabledControl("Unlock inventory ingame", this, &m2);

	OtherHitmarker.SetFileId("auto_hitmarker");
	misctabzin2.PlaceLabledControl("HitMarker", this, &OtherHitmarker);

	m4.SetFileId("auto_4");
	misctabzin2.PlaceLabledControl("Ragdoll force", this, &m4);

	OptionsCompRank.SetFileId("auto_revealrank");
	misctabzin2.PlaceLabledControl("Reveal Matchmaking ranks", this, &OptionsCompRank);

	/*                            `beta`
	m6.SetFileId("auto_6");
	misctabzin2.PlaceLabledControl("preserve killfeed", this, &m6);

	cl_righthand2.SetFileId("cl_righthandx");
	misctabzin2.PlaceLabledControl("cl righthand", this, &cl_righthand2);*/
}

void CMiscTab::Setup()
{
	SetTitle("Configs");

#pragma region Other
	OtherGroup.SetPosition(150, -50);
	OtherGroup.SetText("other");
    OtherGroup.SetSize(220, 250);
	RegisterControl(&OtherGroup);
	
	clantag22.SetFileId("otr_seperateclantag");
	OtherGroup.PlaceLabledControl("Clantag", this, &clantag22);

	OtherClantag.SetFileId("otr_clantag");
	OtherClantag.AddItem("None");
	OtherClantag.AddItem("Static");
	OtherClantag.AddItem("Moving");
	OtherGroup.PlaceLabledControl("", this, &OtherClantag);

	AutoPistol.SetFileId("otr_autopistol");
	OtherGroup.PlaceLabledControl("Auto pistol", this, &AutoPistol);

	OtherThirdperson.SetFileId("aa_thirdpsr");
	OtherGroup.PlaceLabledControl("Thirdperson", this, &OtherThirdperson);

	OtherThirdpersonRange.SetFileId("thirdpersonrange");
	OtherThirdpersonRange.SetBoundaries(1, 1000);
	OtherThirdpersonRange.SetValue(180);
	OtherGroup.PlaceLabledControl("", this, &OtherThirdpersonRange);

	ThirdPersonKeyBind.SetFileId("aa_thirdpersonKey");
	OtherGroup.PlaceLabledControl("", this, &ThirdPersonKeyBind);

	OtherGroup2.SetPosition(375, -50);
	OtherGroup2.SetText("others");
	OtherGroup2.SetSize(220, 250);
	RegisterControl(&OtherGroup2);

	OtherSafeMode.SetState(true);

	configurations2.SetFileId("otr_seperatecfg");
	OtherGroup2.PlaceLabledControl("Configurations", this, &configurations2);

	lstPlayers.SetFileId("configs");
	lstPlayers.AddItem("1");
	lstPlayers.AddItem("2");
	lstPlayers.AddItem("3");
	lstPlayers.AddItem("4");
	lstPlayers.AddItem("5");
	lstPlayers.AddItem("6");
	OtherGroup2.PlaceLabledControl("", this, &lstPlayers);

	SaveButton3.SetFileId("save");
	SaveButton3.SetCallback(SaveLegitCallbk);
	OtherGroup2.PlaceLabledControl("", this, &SaveButton3);

	Seperate2.SetFileId("otr_separetegg");
	OtherGroup2.PlaceLabledControl("", this, &Seperate2);

	LoadButton3.SetFileId("load");
	LoadButton3.SetCallback(LoadLegitCallbk);
	OtherGroup2.PlaceLabledControl("", this, &LoadButton3);



#pragma endregion other random options


}

void g_menu::SetupMenu()
{
	window.Setup();

	GUI.RegisterWindow(&window);
	GUI.BindWindow(VK_INSERT, &window);
}

void g_menu::DoUIFrame()
{


	GUI.Update();
	GUI.Draw();
	
}

