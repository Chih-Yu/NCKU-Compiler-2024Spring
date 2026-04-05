    .class public Main
    .super java/lang/Object
.method public static calculate_pi(I)F
    .limit stack 100
    .limit locals 100
    ldc 3.000000
    fstore 1
    ldc 2.000000
    fstore 2
    iconst_1
    istore 3
        ldc 1
        istore 4
        iload 4
        iload 0
        if_icmplt lesLabel0
        iconst_0
        goto endLabel0
        lesLabel0:
        iconst_1
        endLabel0:
        iload 4
        ldc 1
        iadd
        ldc 4
        f2i
        fload 2
        iload 4
        f2i
        fmul
        fload 2
        iload 4
        f2i
        fmul
        ldc 1.000000
        fadd
        fmul
        fload 2
        iload 4
        f2i
        fmul
        fload 2
        fadd
        fmul
        fdiv
        fstore 5
        iload 3
            fload 1
            fload 5
            fadd
            fstore 1
            iload 3
            iconst_0
            istore 3
            fload 1
            fload 5
            fsub
            fstore 1
            iload 3
            iconst_1
            istore 3
    fload 1
return
.end method
.method public static main([Ljava/lang/String;)V
    .limit stack 100
    .limit locals 100
    ldc 100
    istore 7
    iload 7
    fstore 8
    ldc "Approximation of Pi after ";
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    iload 7
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/print(I)V
    ldc " terms: ";
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
    fload 8
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/print(F)V
    getstatic java/lang/System/out Ljava/io/PrintStream;
    invokevirtual java/io/PrintStream/println()V

    ldc 0
return
.end method
