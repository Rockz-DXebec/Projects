#include <stdio.h>
#include <string.h>

struct student {
    char name[50];
    int rollNumber;
    int studentId;
    float phymarks, mathmarks, csmarks, graphicsmarks, pcmarks;
};

float calculateCGPA(float phy, float math, float cs, float gfx, float pc) {
    int c_phy = 5, c_math = 4, c_cs = 4, c_gfx = 4, c_pc = 3;
    int totalCredits = c_phy + c_math + c_cs + c_gfx + c_pc;
    float phyGP = phy / 10;
    float mathGP = math / 10;
    float csGP = cs / 10;
    float gfxGP = gfx / 10;
    float pcGP = pc / 10;
    float cgpa = (phyGP * c_phy + mathGP * c_math + csGP * c_cs + gfxGP * c_gfx + pcGP * c_pc) / totalCredits;
    return cgpa;
}

const char* calculateGrade(float cgpa) {
    if (cgpa >= 9.0)
        return "A+";
    else if (cgpa >= 8.0)
        return "A";
    else if (cgpa >= 7.0)
        return "B+";
    else if (cgpa >= 6.0)
        return "B";
    else if (cgpa >= 5.0)
        return "C";
    else if (cgpa >= 4.0)
        return "D";
    else
        return "F";
}

int main() {
    long id;
    int n, data, ch;
    char password[50];
    FILE *fp = fopen("studentdata.txt","a");
    if(fp==NULL){
        printf("Error opening file");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    if (pos == 0) {
        fprintf(fp, "%-30s | %13s | %11s | %7s | %6s | %17s | %8s | %26s\n",
                "NAME", "Roll Number", "Student Id", "Physics", "Math",
                "Computer Science", "Graphics", "Professional Communication");
    }
    while (1) {
        printf("Enter ID: ");
        scanf("%ld", &id);
        printf("Enter Password: ");
        scanf(" %20s", password);

        if (id == 12345 && strcmp(password, "Imdad@90") == 0) {
            printf("Login Successful.\n");
            printf("Enter number of students: ");
            scanf("%d", &n);

            struct student s[n];
            for (int i = 0; i < n; i++) {
                printf("Enter Name: ");
                scanf(" %30[^\n]", s[i].name);
                printf("Enter Roll No: ");
                scanf("%d", &s[i].rollNumber);
                printf("Enter Student ID: ");
                scanf("%d", &s[i].studentId);
                printf("Enter Physics Marks: ");
                scanf("%f", &s[i].phymarks);
                printf("Enter Maths Marks: ");
                scanf("%f", &s[i].mathmarks);
                printf("Enter Computer Science Marks: ");
                scanf("%f", &s[i].csmarks);
                printf("Enter Graphics Marks: ");
                scanf("%f", &s[i].graphicsmarks);
                printf("Enter Professional Communication marks: ");
                scanf("%f", &s[i].pcmarks);
                printf("\n");
                fprintf(fp, "%-30s | %13d | %11d | %7.2f | %6.2f | %17.2f | %8.2f | %26.2f\n",
                    s[i].name,s[i].rollNumber,s[i].studentId,
                    s[i].phymarks,s[i].mathmarks,s[i].csmarks,
                    s[i].graphicsmarks,s[i].pcmarks);
            }

            while (1) {
                printf("Enter the serial number of student data you want to see:\n");
                for (int i = 0; i < n; i++) {
                    printf("Sl.no.:%d) %s         SAP ID: %d\n", i, s[i].name, s[i].studentId);
                }
                scanf("%d", &data);

                if (data >= 0 && data < n) {
                    float percentage = ((s[data].phymarks + s[data].mathmarks + s[data].csmarks +
                                         s[data].graphicsmarks + s[data].pcmarks) / 500) * 100;

                    float cgpa = calculateCGPA(s[data].phymarks, s[data].mathmarks, s[data].csmarks,
                                               s[data].graphicsmarks, s[data].pcmarks);
                    const char* grade = calculateGrade(cgpa);

                    printf("Student Name: %s\n", s[data].name);
                    printf("Roll Number: %d\n", s[data].rollNumber);
                    printf("SAP ID: %d\n", s[data].studentId);
                    printf("Physics: %.2f\n", s[data].phymarks);
                    printf("Maths: %.2f\n", s[data].mathmarks);
                    printf("Computer Science: %.2f\n", s[data].csmarks);
                    printf("Graphics: %.2f\n", s[data].graphicsmarks);
                    printf("Professional Communication: %.2f\n", s[data].pcmarks);
                    printf("Total percentage: %.2f\n", percentage);
                    printf("CGPA: %.2f\n", cgpa);
                    printf("Grade: %s\n", grade);
                } else {
                    printf("Invalid student selection.\n");
                }

                printf("Do you want to see another student's data?(1-Yes/2-No): ");
                scanf("%d", &ch);
                if (ch == 2) {
                    printf("Exiting...");
                    fclose(fp);
                    return 0;
                }
            }
        } else {
            printf("Invalid Credentials.\n");
            printf("Try again!\n");
        }
    }
    fclose(fp);
    return 0;
}
