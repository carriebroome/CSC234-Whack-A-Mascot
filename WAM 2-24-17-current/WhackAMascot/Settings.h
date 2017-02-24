class Settings
{
public:
	void settingsController();

private:	
	void screenSelect();
	void mainMenuController();
	void sideMenuController();
	void mascotSelectionPanelController();

	void mascotSetter();

	void drawSideMenuButtons();
	void drawSideMenuMascots();
	void drawMascotSelectionPanel();

	void deleteAll();

	int currentScreen;
	bool screenRedraw;
	bool redrawMenu;

	int selectedMascot;
	int selectedSlot;

};