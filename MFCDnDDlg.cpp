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
	DDX_Control(pDX, IDC_COMBO1, raceCombo);
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


void CMFCDnDDlg::OnBnClickedOk()
{
	int race_index = raceCombo.GetCurSel();
	if (race_index == CB_ERR) {
		CString txt; txt.LoadString(ERROR_MES);
		CString caption; caption.LoadString(ERROR_CAPTION);
		MessageBox(txt, caption, MB_ICONWARNING | MB_OK);
		return;
	}
	StatCalculator sc;
	UpdateStats(sc.CalculateRandomStat() + RaceModifier(race_index, IDC_EDIT1),
		IDC_EDIT1);
	UpdateStats(sc.CalculateRandomStat() + RaceModifier(race_index, IDC_EDIT2),
		IDC_EDIT2);
	UpdateStats(sc.CalculateRandomStat() + RaceModifier(race_index, IDC_EDIT3),
		IDC_EDIT3);
	UpdateStats(sc.CalculateRandomStat() + RaceModifier(race_index, IDC_EDIT4),
		IDC_EDIT4);
	UpdateStats(sc.CalculateRandomStat() + RaceModifier(race_index, IDC_EDIT5),
		IDC_EDIT5);
	UpdateStats(sc.CalculateRandomStat() + RaceModifier(race_index, IDC_EDIT6),
		IDC_EDIT6);
}


int CMFCDnDDlg::RaceModifier(int race_index, UINT id) 
{
	switch (race_index) {
	case 0:
		return HUMAN_MOD;
	case 1:
		return id == IDC_EDIT2 ? ELF_DEX_MOD : 0;
	case 2:
		return id == IDC_EDIT3 ? DWARF_CON_MOD : 0;
	case 3:
		return id == IDC_EDIT4 ? GNOME_INT_MOD : 0;
	}
}

void CMFCDnDDlg::UpdateStats(int n, UINT id)
{
	CString s; s.Format(_T("%d"), n);
	GetDlgItem(id)->SetWindowText(s);
}


void CMFCDnDDlg::OnBnClickedCancel()
{
	CDialogEx::OnCancel();
}


CString CMFCDnDDlg::RaceExplaModifier(int race_index)
{
	int id;
	switch (race_index) {
	case 0: id = HUMAN_RACIAL_BONUS; break;
	case 1: id = ELF_RACIAL_BONUS; break;
	case 2: id = DWARF_RACIAL_BONUS; break;
	case 3: id = GNOME_RACIAL_BONUS; break;
	}
	CString s; s.LoadString(id);
	return s;
}

void CMFCDnDDlg::OnCbnSelchangeCombo1()
{
	SetDlgItemText(IDC_EDIT7, RaceExplaModifier(raceCombo.GetCurSel()));
}

