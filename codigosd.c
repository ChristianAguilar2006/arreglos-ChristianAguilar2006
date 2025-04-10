#include <stdio.h>
#include <string.h>

int main() {
    char estudiantes[5][30] = {{0}};
    char materias[3][30] = {{0}};
    float calificaciones[5][3];
    int opc = 0, count = 0, val, len, aprobados = 0, reprobados = 0;
    int contestudiantes = 0;

    do {
        printf("\n1. Ingrese materias \n");
        printf("2. Ingrese estudiantes \n");
        printf("3. Calculo promedio de calificaciones\n");
        printf("4. Calculo promedio por asignatura \n");
        printf("5. Jerarquia de calificaciones\n");
        printf("6. Aprobados y reprobados\n");
        printf("7. Salir\n>>");
        val = scanf("%i", &opc);
        while (val == 0) {
            fflush(stdin);
            printf("ERROR: solo debe ingresar numeros \n>>");
            val = scanf("%i", &opc);
        }

        switch (opc) {
        case 1:
            if (strlen(materias[0]) > 0 && strlen(materias[1]) > 0 && strlen(materias[2]) > 0) {
            printf("\nYa se han ingresado todas las materias.\n");
            break;
            }
    
            for (int i = 0; i < 3; i++) {
                printf("Ingrese el nombre de la materia %d: ", i + 1);
                fflush(stdin);
                fgets(materias[i], 30, stdin);
                len = strlen(materias[i]);
                if (len > 0 && materias[i][len - 1] == '\n') {
                materias[i][len - 1] = '\0';
                }
            }
    
            printf("\nMaterias ingresadas:\n");
            for (int i = 0; i < 3; i++) {
                printf("%d. %s\n", i + 1, materias[i]);
            }
            break;
        case 2:
            if (contestudiantes >= 5) {
                printf("\nCUPOS DE ESTUDIANTES LLENOS\n");
                break;
            }

            if (strlen(materias[0]) == 0 || strlen(materias[1]) == 0 || strlen(materias[2]) == 0) {
                printf("\nPor favor, ingrese las materias primero\n");
                break;
            }

            printf("\nINGRESE EL NOMBRE DEL ESTUDIANTE %d: ", contestudiantes + 1);
            fflush(stdin);
            fgets(estudiantes[contestudiantes], 30, stdin);
            int lenEst = strlen(estudiantes[contestudiantes]);
            if (lenEst > 0 && estudiantes[contestudiantes][lenEst - 1] == '\n') {
                estudiantes[contestudiantes][lenEst - 1] = '\0';
            }

            printf("\nIngrese las calificaciones del estudiante %s:\n", estudiantes[contestudiantes]);
            for (int i = 0; i < 3; i++) {
                printf("ASIGNATURA %s: ", materias[i]);
                val = scanf("%f", &calificaciones[contestudiantes][i]);
                while (val == 0 || calificaciones[contestudiantes][i] < 0 || calificaciones[contestudiantes][i] > 10) {
                    fflush(stdin);
                    printf("Ingrese un valor valido (0 a 10): ");
                    val = scanf("%f", &calificaciones[contestudiantes][i]);
                }
            }

            contestudiantes++;
            break;

        case 3:
            if (contestudiantes == 0) {
                printf("No se han ingresado estudiantes\n");
                break;
            }
            for (int i = 0; i < contestudiantes; i++) {
                float suma = 0;
                for (int j = 0; j < 3; j++) {
                    suma += calificaciones[i][j];
                }
                float promedio = suma / 3;
                printf("Promedio de %s: %.2f\n", estudiantes[i], promedio);
            }
            break;

        case 4:
            if (contestudiantes == 0) {
                printf("No se han ingresado estudiantes\n");
                break;
            }
            for (int j = 0; j < 3; j++) {
                float suma = 0;
                for (int i = 0; i < contestudiantes; i++) {
                    suma += calificaciones[i][j];
                }
                float promedio = suma / contestudiantes;
                printf("Promedio en %s: %.2f\n", materias[j], promedio);
            }
            break;

        case 5:
            if (contestudiantes == 0) {
                printf("No se han ingresado estudiantes\n");
                break;
            }

            printf("\n--- Maximas y minimas por estudiante ---\n");
            for (int i = 0; i < contestudiantes; i++) {
                float max = calificaciones[i][0];
                float min = calificaciones[i][0];
                for (int j = 1; j < 3; j++) {
                    if (calificaciones[i][j] > max) max = calificaciones[i][j];
                    if (calificaciones[i][j] < min) min = calificaciones[i][j];
                }
                printf("%s: Maxima = %.2f, Minima = %.2f\n", estudiantes[i], max, min);
            }

            printf("\n--- Maximas y minimas por asignatura ---\n");
            for (int j = 0; j < 3; j++) {
                float max = calificaciones[0][j];
                float min = calificaciones[0][j];
                for (int i = 1; i < contestudiantes; i++) {
                    if (calificaciones[i][j] > max) max = calificaciones[i][j];
                    if (calificaciones[i][j] < min) min = calificaciones[i][j];
                }
                printf("%s: Maxima = %.2f, Minima = %.2f\n", materias[j], max, min);
            }
            break;

        case 6:
            if (contestudiantes == 0) {
                printf("No se han ingresado estudiantes\n");
                break;
            }
            aprobados = 0;
            reprobados = 0;
            for (int i = 0; i < contestudiantes; i++) {
                float suma = 0;
                for (int j = 0; j < 3; j++) {
                    suma += calificaciones[i][j];
                }
                float promedio = suma / 3;
                if (promedio >= 7.0) {
                    aprobados++;
                } else {
                    reprobados++;
                }
            }
            printf("\nEstudiantes Aprobados: %d\n", aprobados);
            printf("Estudiantes Reprobados: %d\n", reprobados);
            break;

        default:
            if (opc != 7)
                printf("Opcion no valida\n");
            break;
        }
    } while (opc != 7);

    printf("GRACIAS POR USAR EL PROGRAMA - THE END - un diez :( ");
    return 0;
}