#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilha.h"

void sortStack(node **stack, int retirar)
{
    node *auxStack = NULL;
    node *stackFinal = NULL;
    int min;

    createStack(auxStack);
    createStack(stackFinal);

    while(length((*stack)))
    {
        min = 10;

        while(length((*stack)))
        {
            if(top((*stack)) < min)
            {
                min = top((*stack));
            }
            push(&auxStack, top((*stack)));
            pop(stack);
        }

        while(length(auxStack))
        {
            if(top(auxStack) != min)
            {
                push(stack, top(auxStack));
                pop(&auxStack);
            }
            else if(retirar > 0)
            {
                pop(&auxStack);
                retirar--;
            }
            else
            {
                push(&stackFinal, top(auxStack));
                pop(&auxStack);
            }
        }
    }

    *stack = stackFinal;
}

void pushStack(node **stackTotal)
{
    char c;
    int valid = 1;
    int intC;
    int isReal = 0;

    while(scanf("%c", &c) && c != '\n')
    {
        intC = c - '0';

        if((!length(*stackTotal)) && (intC == -2 || intC == -4))
        {
            valid = 0;
        }
        if((intC < 0 && intC != -2 && intC != -4) || (intC > 9))
        {
            valid = 0;
        }
        else
        {
            if(intC == -2 || intC == -4) isReal++;
            push(stackTotal, intC);
        }
    }

    if(valid == 0 || isReal > 1)
    {
        printf("Valor incorreto. Digite novamente: ");
        
        while(length(*stackTotal))
        {
            pop(stackTotal);
        }
        pushStack(stackTotal);
    }
}

int quantidade_a_retirar(int max)
{
    int valor = 0;
    int intC;
    int valid = 1;
    char c;

    while(scanf("%c", &c) && c != '\n')
    {
        intC = c - '0';
        if(isdigit(c) == 0 || intC > max || intC < 0)
        {
            valid = 0;
        }
        else
        {
            valor *= 10;
            valor += intC;
        }
    }

    if(valid == 0)
    {
        printf("Digite novamente: ");
        valor = quantidade_a_retirar(max);
    }

    return valor;
}

void break_stack(node **stack, node **stackInteira, node **stackFracionaria)
{
    node *stackTemp = NULL;
    int isNatural = 1;

    createStack(stackTemp);

    while(length(*stack) && (top(*stack) != -2) && (top(*stack) != -4))
    {
        push(&stackTemp, top(*stack));
        pop(stack);
    }

    if((top(*stack) == -2) || (top(*stack) == -4))
    {
        while(length(stackTemp))
        {
            push(stackFracionaria, top(stackTemp));
            pop(&stackTemp);
        }
    }
    else
    {
        while(length(stackTemp))
        {
            push(stackInteira, top(stackTemp));
            pop(&stackTemp);
        }
    }

    while(length(*stack))
    {
        if(top(*stack) == -2 || top(*stack) == -4)
        {
            pop(stack);
            isNatural = 0;
        }

        push(&stackTemp, top(*stack));
        pop(stack);
    }

    if(!isNatural)
    {
        while(length(stackTemp))
        {
            push(stackInteira, top(stackTemp));
            pop(&stackTemp);
        }
    }
}

void joinStacks(node **stack, node **stackInteira, node **stackFracionaria)
{
    node *stackTemp = NULL;

    while(length(*stackFracionaria))
    {
        push(&stackTemp, top(*stackFracionaria));
        pop(stackFracionaria);
    }

    while(length(stackTemp))
    {
        push(stack, top(stackTemp));
        pop(&stackTemp);
    }

    if(length(*stack))
    {
        push(stack, -2);
    }
    if(!length(*stackInteira)) push(stack, 0);
    else
    {
        while(length(*stackInteira))
        {
            push(&stackTemp, top(*stackInteira));
            pop(stackInteira);
        }

        while(length(stackTemp))
        {
            push(stack, top(stackTemp));
            pop(&stackTemp);
        }
    }
}

void show_stack(node *stack)
{
    while(length(stack))
    {
        if(stack->info == -2) printf(",");
        else printf("%d", stack->info);
        pop(&stack);
    }
}

int main()
{
    node *stackTotal = NULL;
    node *stackInteira = NULL;
    node *stackFracionaria = NULL;
    int retirar_inteiros, retirar_fracionarios;

    createStack(stackTotal);

    printf("\nDigite um número decimal: ");
    pushStack(&stackTotal);

    break_stack(&stackTotal, &stackInteira, &stackFracionaria);

    if(length(stackInteira))
    {
        printf("Digite um valor para K: ");
        retirar_inteiros = quantidade_a_retirar(length(stackInteira));
    }
        if(length(stackFracionaria))
    {
        printf("Digite um valor  para W: ");
        retirar_fracionarios = quantidade_a_retirar(length(stackFracionaria));
    }

    sortStack(&stackInteira, retirar_inteiros);
    sortStack(&stackFracionaria, retirar_fracionarios);
    joinStacks(&stackTotal, &stackInteira, &stackFracionaria);

    printf("Pilha ordenada: ");
    show_stack(stackTotal);

    return 0;
}