#include <stdio.h> // printf() 사용 목적
#include <windows.h>  // 윈도우 프로세스 실행 목적 
#include <tchar.h> // Windows 환경에서 유니코드 및 멀티바이트 문자열을 지원 목적

using namespace std;

int main() {
    // 실행할 프로세스 경로
    LPCTSTR applicationPath = _T("C:\\Program Files\\Cisco Packet Tracer 8.2.1\\bin\\PacketTracer.exe");

    // 커맨드 라인 매개변수 (필요에 따라 조절)
    LPCTSTR commandLineArgs = _T("");

    // 프로세스 정보 구조체
    PROCESS_INFORMATION processInfo; //구조체 설정 추가 시도 필요
    // 시작 정보 구조체
    STARTUPINFO startupInfo; //구조체 설정 추가 시도 필요

    // STARTUPINFO 구조체 초기화
    ZeroMemory(&startupInfo, sizeof(startupInfo));
    startupInfo.cb = sizeof(startupInfo);

    // 프로세스를 생성
    if (CreateProcess(
        applicationPath,     // 실행 파일 경로
        (LPTSTR)commandLineArgs, // 커맨드 라인 매개변수
        NULL,                // 보안 속성 (기본값)
        NULL,                // 보안 속성 (기본값)
        FALSE,               // 핸들 상속 여부
        0,                   // 작업 플래그 (기본값)
        NULL,                // 환경 변수 (부모의 것을 사용)
        NULL,                // 현재 디렉터리 (부모의 것을 사용)
        &startupInfo,        // STARTUPINFO 구조체
        &processInfo         // PROCESS_INFORMATION 구조체
    )) {
        // 프로세스 생성 성공
        printf("Success To Create Process, No Error");
        CloseHandle(processInfo.hThread);
        CloseHandle(processInfo.hProcess);
    }
    else {
        // 프로세스 생성 실패
        _tprintf(_T("Failed to create process, Error %d\n"), GetLastError());
    }

    return 0;
}


