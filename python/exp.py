gabarito = [
    "AB+",
    "ABC*+",
    "AB+C*",
    "ABC*+D-",
    "ABCDE-*+*",
    "AB+CD+*",
    "ABC-D*EF+/+",
    "ABC-D*EFG*+/+",
    "ABC-DE F*+*+",  # atenção: espaço só pra leitura → "ABC-DEF*+*+"
    "ABCD/E+F-G*-H*+",
    "ABC*+DE/F-G*-",
    "ABCDEF-+*+*",
    "AB+C*DE--FG+*",
    "AB+C+D+",
    "AB*CD*+",
    "AB+C+DE+F+*",
    "ABCDEF+*+*+",
    "ABCD EF+*+*+GH+*+",  # leitura → "ABCD EF+*+*+GH+*+"
    "AB+CD EF-+*+G/",     # leitura → "AB+CDEF-+*G/"
    "ABC-DEFGH/-*+*+I+"
]

expressoes = [
        "A+B",
        "A+B*C",
        "(A+B)*C",
        "A+B*C-D",
        "A*(B+C*(D-E))",
        "(A+B)*(C+D)",
        "A+B*(C-D)/(E+F)",
        "A+B*(C-D)/(E+F*G)",
        "A+(B-C)*(D+(E*F))",
        "A+B*(C-(D/E+F)*G)*H",
        "(A+B*C)-(D/E-F)*G",
        "A*(B+C*(D+(E-F)))",
        "((A+B)*C-(D-E))*(F+G)",
        "A+B+C+D",
        "A*B+C*D",
        "(A+B+C)*(D+E+F)",
        "A+(B*(C+(D*(E+F))))",
        "A+B*(C+D*(E+F*(G+H)))",
        "((A+B)*(C+D*(E-F)))/G",
        "A+(B-C)*(D+E*(F-G/H))+I"
]