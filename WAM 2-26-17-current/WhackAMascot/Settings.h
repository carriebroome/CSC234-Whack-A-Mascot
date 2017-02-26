class Settings
{
public:
	void settingsController();

private:	
	void screenSelect();
	void mainMenuController();
	void sideMenuController();
	void mascotSelectionPanelController();

	void editMascot();
	void randomMascot();
	void mascotSetter();

	void drawSideMenuButtons();
	void drawSideMenuMascots();
	void drawMascotSelectionPanel();

	void deleteAll();

	int currentScreen;
	bool screenRedraw;

	int selectedMascot;
	int selectedSlot;
	int randomMascotID;
};