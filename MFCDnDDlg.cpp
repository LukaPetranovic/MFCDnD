
// MFCDnDDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCDnD.h"
#include "MFCDnDDlg.h"
#include "afxdialogex.h"
#include <random>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCDnDDlg dialog



CMFCDnDDlg::CMFCDnDDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCDND_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	Race humanRace, elfRace;
	humanRace.name = _T("Human");
	race.push_back(humanRace);
	elfRace.name = _T("Elf");
	race.push_back(elfRace);

}

void CMFCDnDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCDnDDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCDnDDlg::OnBnClickedOk)
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

	raceCombo.Attach(GetDlgItem(IDC_COMBO1)->GetSafeHwnd());

	CComboBox* pRaceCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	for (const Race& race : race) {
		pRaceCombo->AddString(race.name);
	}

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



void CMFCDnDDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	int selectedRaceIndex = raceCombo.GetCurSel();


	if (selectedRaceIndex != CB_ERR && selectedRaceIndex == 0) {
		Race selectedRace = race[selectedRaceIndex];
		//int baseStat = 8;


		//CString strModifier;
		strModifier.LoadString(IDS_STR_MOD);

		int modifier = _wtoi(strModifier);

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<>dis(1, 6);

		int randomNumbers[4];
		for (int i = 0; i < 4; ++i) {
			randomNumbers[i] = dis(gen);
		}

		int smallestNumber = randomNumbers[0];
		for (int i = 1; i < 4; ++i) {
			if (randomNumbers[i] < smallestNumber) {
				smallestNumber = randomNumbers[i];
			}
		}

		int sum = randomNumbers[0] + randomNumbers[1] + randomNumbers[2] + randomNumbers[3];
		int sum3 = sum - smallestNumber;

		int modifiedStat = sum3 + modifier;

		//CString modifiedStatStr;
		modifiedStatStr.Format(_T("%d"), modifiedStat);

		CEdit* pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);

	}

	else if (selectedRaceIndex != CB_ERR && selectedRaceIndex == 1) {
		Race selectedRace = race[selectedRaceIndex];
		//int baseStat = 8;


		//CString strModifier;
		strModifier.LoadString(IDS_STR_MOD);

		int modifier = _wtoi(strModifier);

		int modifiedStat = baseStat + modifier + 2;

		//CString modifiedStatStr;
		modifiedStatStr.Format(_T("%d"), modifiedStat);

		CEdit* pStrEdit = (CEdit*)GetDlgItem(IDC_EDIT1);
		pStrEdit->SetWindowText(modifiedStatStr);
	}
	//CDialogEx::OnOK();
}
