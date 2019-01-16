struct Address {
    char street[50], city[30], state[30];
};

struct Student {
    int age, rollNumber;
    char name[50];
    float m1, m2, avg, total;
    char grade;
    struct Address address;
};