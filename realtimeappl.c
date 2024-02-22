#include <stdio.h>

#define MAX_USERS 100

int adjacency_matrix[MAX_USERS][MAX_USERS] = {0};
char user_names[MAX_USERS][50]; 
int num_users = 0;

void add_user(char name[]) {
    if (num_users < MAX_USERS) {
        strcpy(user_names[num_users], name);
        num_users++;
        printf("User '%s' added successfully.\n", name);
    } else {
        printf("Maximum user limit reached.\n");
    }
}

void add_friend(int user1, int user2) {
    adjacency_matrix[user1][user2] = 1;
    adjacency_matrix[user2][user1] = 1;
    printf("Friendship established between '%s' and '%s'.\n", user_names[user1], user_names[user2]);
}

int are_friends(int user1, int user2) {
    return adjacency_matrix[user1][user2];
}

void print_friends(int user) {
    printf("Friends of '%s':\n", user_names[user]);
    for (int i = 0; i < num_users; i++) {
        if (adjacency_matrix[user][i] == 1) {
            printf("- %s\n", user_names[i]);
        }
    }
}

int main() {
    add_user("Alice");
    add_user("Bob");
    add_user("Charlie");

    add_friend(0, 1);  // Alice is friends with Bob
    add_friend(0, 2);  // Alice is friends with Charlie

    printf("Are Alice and Bob friends? %s\n", are_friends(0, 1) ? "Yes" : "No");
    printf("Are Alice and Charlie friends? %s\n", are_friends(0, 2) ? "Yes" : "No");

    print_friends(0);  // Print Alice's friends

    return 0;
}