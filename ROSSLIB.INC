Cnt         PROC   ;��楤�� ������ ���न��� � ᬥ饭��
            push   ax cx      ;���. ॣ�����
            mov    ax,video   ;����㧪� ����
            mov    es,ax      ;�����ᥣ����
            xor    di,di      ;������ ᬥ饭��
            xor    cx,cx      ;������ ���稪
            mov    cl,dh      ;� ���稪 - ���-�� ��ப
cntloop:    add    di,0A0h    ;�������� ���-�� ���� � ��ப�
            loop   cntloop
            xor    ax,ax      ;���᫥���
            mov    al,dl      ;������⢠
            shl    al,1       ;���� � �������� ��ப�
            add    di,ax      ;����������  � ᬥ饭��
            pop    cx ax      ;�����. ॣ�����
            ret               ;������
Cnt         ENDP

OutStr      PROC              ;��楤�� �뢮�� ��ப�
            push   ax         ;���. ॣ����
            mov    ah,9       ;�뢮� ��ப� ᨬ����� ��
            int    21h        ;���᮫�
            pop    ax         ;�����. ॣ����
            ret               ;������
OutStr      ENDP

MoveAt      PROC              ;��楤�� ��⠭���� �����
            push   ax bx      ;���. ॣ�����
            xor    bx,bx      ;�������࠭�� 0
            mov    ah,02      ;�㭪�� ��⠭����
            int    10h        ;�맮� �㭪樨
            pop    bx ax      ;�����. ॣ�����
            ret               ;������
MoveAt      ENDP

Cls         PROC   ;��楤�� ���⪨ �������� ������ ��࠭�
            mov    ax,0600h     ;�㭪�� ���⪨ ��࠭�
            int    10h          ;�맮� �㭪樨
            ret                 ;������
Cls         ENDP

DrawMenu    PROC                ;��楤�� �뢮�� ����
            DrawBut  B1         ;�ᮢ���� "������"
            DrawBut  B2
            DrawBut  B3
            DrawBut  B4
            ret                 ;������
DrawMenu    ENDP

HideCur     PROC                ;��楤�� �몫�祭�� �����
            push     ax cx      ;��࠭��� ॣ�����
            mov      ah,01h     ;��⠭���� ࠧ��� � ��� �����
            mov      cx,2000h   ;20 - �������� �����
            int      10h        ;�맮� �㭪権
            pop      cx ax      ;����⠭����� ॣ�����
            ret                 ;������
HideCur     ENDP

VMode       PROC                 ;��楤�� ��⠭���� �����०���
            push   ax bx         ;��࠭���� ࠡ��� ॣ���஢
            mov    ax,0003h      ;��⠭���� �����०���
            int    10h           ;16 �. 80�25
            mov    ax,1003h      ;���樠������ EGA-�������
            mov    bl,0          ;��⠭���� �મ�� => 16 梥⮢
            int    10h
            pop    bx ax         ;����⠭������� ॣ���஢
            ret                  ;������
VMode       ENDP