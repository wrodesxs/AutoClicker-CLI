#include <windows.h>
#include <stdbool.h>
#include <stdio.h>

#define __DefaultDelay 60

void menu(int op)
{
    printf("Autoclicker para jogos: \n\n\n");
    printf("[1] Autoclick\n\n");
    printf("[2] Opcoes Avancadas\n\n");
    printf("[99] Sair\n\n");
    printf("Opcao -> ");
    scanf("%d", &op);
}

int main(int op)
{
    static bool OK = true;
    int delay;
    int opAvan;

    printf("Autoclicker para jogos: \n\n\n");
    printf("[1] Autoclick\n\n");
    printf("[2] Opcoes Avancadas\n\n");
    printf("[99] Sair\n\n");
    printf("Opcao -> ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        while (OK)
        {
            while (GetAsyncKeyState(VK_LBUTTON))
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                Sleep(__DefaultDelay);
                mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            }
        }
        break;
    case 2:
        system("cls");
        printf("Opcoes Avancadas: \n\n\n");
        printf("[1] Delay\n\n");
        printf("[99] Voltar para o menu\n\n");
        printf("Opcao -> ");
        scanf("%d", &opAvan);

        switch (opAvan)
        {
        case 1:
            system("cls");
            printf("Delay -> ");
            scanf("%d", &delay);

            while (OK)
            {
                while (GetAsyncKeyState(VK_LBUTTON))
                {
                    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
                    Sleep(delay);
                    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                }
            }
            break;
        case 99:
            system("cls");
            menu(op); 
            break;

        default:
            printf("Escolhe uma opcao valida");
        }

        break;
    case 99:
        exit(1);
        break;

    default:
        printf("Escolhe uma opcao valida");
    }
}

