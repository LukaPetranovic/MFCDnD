
// MFCDnDDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCDnD.h"
#include "MFCDnDDlg.h"
#include "afxdialogex.h"
#include "StatCalculator.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDnDDlg dialog



CMFCDnDDlg::CMFCDnDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	Race humanRace, elfRace, dwarfRace, gnomeRace;
	humanRace.name = _T("Human");
	race.push_back(humanRace);
	elfRace.name = _T("Elf");
	race.push_back(elfRace);
	dwarfRace.name = _T("Dwarf");
	race.push_back(dwarfRace);
	gnomeRace.name = _T("Gnome");
	race.push_back(gnomeRace);

}

void CMFCDnDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDnDDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCDnDDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCDnDDlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CMFCDnDDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CMFCDnDDlg message handlers

BOOL CMFCDnDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	//raceCombo.Attach(GetDlgItem(IDC_COMBO1)->GetSafeHwnd());
	raceCombo.SubclassDlgItem(IDC_COMBO1, this);
	CComboBox* pRaceCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	for (const Race& r : race) {
		pRaceCombo->AddString(r.name);
	}

	CEdit* pRacialBonusesEdit = (CEdit*)GetDlgItem(IDC_EDIT7);
	pRacialBonusesEdit->SetWindowText(_T("Select a race"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCDnDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCDnDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCDnDDlg::UpdateStats(int randomStat, const CString& modifierStr, CEdit* EditControl)
{
	int modifier = _wtoi(modifierStr);
	CString modifiedStatStr;
	modifiedStatStr.Format(_T("%d"), randomStat);
	EditControl->SetWindowText(modifiedStatStr);
}

void GenerateRandomStats(int& randomStrStat, int& randomDexStat, int& randomConStat, int& randomIntStat, int& randomWisStat, int& randomChaStat, StatCalculator statCalculator) {
	randomStrStat = statCalculator.CalculateRandomStat();
	randomDexStat = statCalculator.CalculateRandomStat();
	randomConStat = statCalculator.CalculateRandomStat();
	randomIntStat = statCalculator.CalculateRandomStat();
	randomWisStat = statCalculator.CalculateRandomStat();
	randomChaStat = statCalculator.CalculateRandomStat();
}



void CMFCDnDDlg::OnBnClickedOk()
{

	int selectedRaceIndex = raceCombo.GetCurSel();

	if (selectedRaceIndex == CB_ERR) {
		MessageBox(_T("Not a valid selection."), _T("Error"), MB_ICONERROR | MB_OK);
		return;
	}
	Race selectedRace;
	int randomStrStat, randomDexStat, randomConStat, randomIntStat, randomWisStat, randomChaStat, modifier;
	CEdit* pStrEdit, * pDexEdit, * pConEdit, * pIntEdit, * pWisEdit, * pChaEdit;

	StatCalculator statCalculator;
	GenerateRandomStats(randomStrStat, randomDexStat, randomConStat, randomIntStat, randomWisStat, randomChaStat, statCalculator);

	switch (selectedRaceIndex) {
	case 0:

		strModifier.LoadString(HUMAN_STR_MOD);
		dexModifier.LoadString(HUMAN_DEX_MOD);
		conModifier.LoadString(HUMAN_CON_MOD);
		intModifier.LoadString(HUMAN_INT_MOD);
		wisModifier.LoadString(HUMAN_WIS_MOD);
		chaModifier.LoadString(HUMAN_CHA_MOD);

		modifier = _wtoi(strModifier);
		randomStrStat += modifier;
		modifiedStatStr.Format(_T("%d"), randomStrStat);
		pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);

		modifier = _wtoi(dexModifier);
		randomDexStat += modifier;
		modifiedStatDex.Format(_T("%d"), randomDexStat);
		pDexEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		pDexEdit->SetWindowText(modifiedStatDex);

		modifier = _wtoi(conModifier);
		randomConStat += modifier;
		modifiedStatCon.Format(_T("%d"), randomConStat);
		pConEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
		pConEdit->SetWindowText(modifiedStatCon);

		modifier = _wtoi(intModifier);
		randomIntStat += modifier;
		modifiedStatInt.Format(_T("%d"), randomIntStat);
		pIntEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pIntEdit->SetWindowText(modifiedStatInt);

		modifier = _wtoi(wisModifier);
		randomWisStat += modifier;
		modifiedStatWis.Format(_T("%d"), randomWisStat);
		pWisEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pWisEdit->SetWindowText(modifiedStatWis);

		modifier = _wtoi(chaModifier);
		randomChaStat += modifier;
		modifiedStatCha.Format(_T("%d"), randomChaStat);
		pChaEdit = (CEdit*)GetDlgItem(IDC_EDIT6);
		pChaEdit->SetWindowText(modifiedStatCha);
		break;
	case 1:

		dexModifier.LoadStringW(ELF_DEX_MOD);

		modifiedStatStr.Format(_T("%d"), randomStrStat);
		pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);

		modifier = _wtoi(dexModifier);
		randomDexStat += modifier;
		modifiedStatDex.Format(_T("%d"), randomDexStat);
		pDexEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		pDexEdit->SetWindowText(modifiedStatDex);

		modifiedStatCon.Format(_T("%d"), randomConStat);
		pConEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
		pConEdit->SetWindowText(modifiedStatCon);

		modifiedStatInt.Format(_T("%d"), randomIntStat);
		pIntEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pIntEdit->SetWindowText(modifiedStatInt);

		modifiedStatWis.Format(_T("%d"), randomWisStat);
		pWisEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pWisEdit->SetWindowText(modifiedStatWis);

		modifiedStatCha.Format(_T("%d"), randomChaStat);
		pChaEdit = (CEdit*)GetDlgItem(IDC_EDIT6);
		pChaEdit->SetWindowText(modifiedStatCha);
		break;

	case 2:

		conModifier.LoadString(DWARF_CON_MOD);

		modifiedStatStr.Format(_T("%d"), randomStrStat);
		pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);

		modifiedStatDex.Format(_T("%d"), randomDexStat);
		pDexEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		pDexEdit->SetWindowText(modifiedStatDex);

		modifier = _wtoi(conModifier);
		randomConStat += modifier;
		modifiedStatCon.Format(_T("%d"), randomConStat);
		pConEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
		pConEdit->SetWindowText(modifiedStatCon);

		modifiedStatInt.Format(_T("%d"), randomIntStat);
		pIntEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pIntEdit->SetWindowText(modifiedStatInt);

		modifiedStatWis.Format(_T("%d"), randomWisStat);
		pWisEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pWisEdit->SetWindowText(modifiedStatWis);

		modifiedStatCha.Format(_T("%d"), randomChaStat);
		pChaEdit = (CEdit*)GetDlgItem(IDC_EDIT6);
		pChaEdit->SetWindowText(modifiedStatCha);
		break;

	case 3:
		intModifier.LoadString(GNOME_INT_MOD);

		modifiedStatStr.Format(_T("%d"), randomStrStat);
		pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);

		modifiedStatDex.Format(_T("%d"), randomDexStat);
		pDexEdit = (CEdit*)GetDlgItem(IDC_EDIT2);
		pDexEdit->SetWindowText(modifiedStatDex);

		modifiedStatCon.Format(_T("%d"), randomConStat);
		pConEdit = (CEdit*)GetDlgItem(IDC_EDIT3);
		pConEdit->SetWindowText(modifiedStatCon);

		modifier = _wtoi(intModifier);
		randomIntStat += modifier;
		modifiedStatInt.Format(_T("%d"), randomIntStat);
		pIntEdit = (CEdit*)GetDlgItem(IDC_EDIT4);
		pIntEdit->SetWindowText(modifiedStatInt);

		modifiedStatWis.Format(_T("%d"), randomWisStat);
		pWisEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
		pWisEdit->SetWindowText(modifiedStatWis);

		modifiedStatCha.Format(_T("%d"), randomChaStat);
		pChaEdit = (CEdit*)GetDlgItem(IDC_EDIT6);
		pChaEdit->SetWindowText(modifiedStatCha);
		break;
	}
}


void CMFCDnDDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CMFCDnDDlg::OnCbnSelchangeCombo1()
{
	int selectedRaceIndex = raceCombo.GetCurSel();

	switch (selectedRaceIndex) {
	case 0: // Human
		racialBonuses = _T("Human gives +1 Every score");
		break;
	case 1: // Elf
		racialBonuses = _T("Elf gives +2 Dexterity");
		break;
	case 2: // Dwarf
		racialBonuses = _T("Dwarf gives +2 Constitution");
		break;
	case 3: // Gnome
		racialBonuses = _T("Gnome gives +2 Intelligence");
		break;
	}

	CEdit* pRacialBonusesEdit = (CEdit*)GetDlgItem(IDC_EDIT7);
	pRacialBonusesEdit->SetWindowText(racialBonuses);
}
