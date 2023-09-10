#include "pch.h"
#include "framework.h"
#include "MFCDnD.h"
#include "MFCDnDDlg.h"
#include "afxdialogex.h"
#include "StatCalculator.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




CMFCDnDDlg::CMFCDnDDlg(CWnd* pParent)
	: CDialogEx(IDD_MFCDND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


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



BOOL CMFCDnDDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);

	raceCombo.SubclassDlgItem(IDC_COMBO1, this);
	CComboBox* pRaceCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);

	CEdit* pRacialBonusesEdit = (CEdit*)GetDlgItem(IDC_EDIT7);
	pRacialBonusesEdit->SetWindowText(_T("Select a race to show benefits"));

	return TRUE;
}


void CMFCDnDDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

HCURSOR CMFCDnDDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCDnDDlg::UpdateStats(int randomStat, const CString& modifierStr, CEdit* EditControl)
{
	CString modifiedStatStr;
	modifiedStatStr.Format(_T("%d"), randomStat);
	EditControl->SetWindowText(modifiedStatStr);
}


void CMFCDnDDlg::RaceModifiers(int selectedRaceIndex, int& randomStrStat, int& randomDexStat, int& randomConStat, int& randomIntStat, int& randomWisStat, int& randomChaStat) {
	switch (selectedRaceIndex) {
	case 0:
		randomStrStat += HUMAN_MOD;
		randomDexStat += HUMAN_MOD;
		randomConStat += HUMAN_MOD;
		randomIntStat += HUMAN_MOD;
		randomWisStat += HUMAN_MOD;
		randomChaStat += HUMAN_MOD;
		break;
	case 1:
		randomDexStat += ELF_DEX_MOD;
		break;
	case 2:
		randomConStat += DWARF_CON_MOD;
		break;
	case 3:
		randomIntStat += GNOME_INT_MOD;
		break;
	}
}


void CMFCDnDDlg::OnBnClickedOk()
{
	StatCalculator statCalculator;
	int randomStrStat = statCalculator.CalculateRandomStat();
	int randomDexStat = statCalculator.CalculateRandomStat();
	int randomConStat = statCalculator.CalculateRandomStat();
	int randomIntStat = statCalculator.CalculateRandomStat();
	int randomWisStat = statCalculator.CalculateRandomStat();
	int randomChaStat = statCalculator.CalculateRandomStat();

	int selectedRaceIndex = raceCombo.GetCurSel();

	if (selectedRaceIndex == CB_ERR) {
		errorMessage.LoadString(ERROR_MES);
		MessageBox(errorMessage, _T("Warning"), MB_ICONWARNING | MB_OK);
		return;
	}

	RaceModifiers(selectedRaceIndex, randomStrStat, randomDexStat, randomConStat, randomIntStat, randomWisStat, randomChaStat);

	UpdateStats(randomStrStat, strModifier, (CEdit*)GetDlgItem(IDC_EDIT1));
	UpdateStats(randomDexStat, dexModifier, (CEdit*)GetDlgItem(IDC_EDIT2));
	UpdateStats(randomConStat, conModifier, (CEdit*)GetDlgItem(IDC_EDIT3));
	UpdateStats(randomIntStat, intModifier, (CEdit*)GetDlgItem(IDC_EDIT4));
	UpdateStats(randomWisStat, wisModifier, (CEdit*)GetDlgItem(IDC_EDIT5));
	UpdateStats(randomChaStat, chaModifier, (CEdit*)GetDlgItem(IDC_EDIT6));
}


void CMFCDnDDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


void CMFCDnDDlg::OnCbnSelchangeCombo1()
{
	int selectedRaceIndex = raceCombo.GetCurSel();

	switch (selectedRaceIndex) {
	case 0:
		racialBonuses = _T("Human gives +1 Every score");
		break;
	case 1:
		racialBonuses = _T("Elf gives +2 Dexterity");
		break;
	case 2:
		racialBonuses = _T("Dwarf gives +2 Constitution");
		break;
	case 3:
		racialBonuses = _T("Gnome gives +2 Intelligence");
		break;
	}

	CEdit* pRacialBonusesEdit = (CEdit*)GetDlgItem(IDC_EDIT7);
	pRacialBonusesEdit->SetWindowText(racialBonuses);
}
