

    #include <stdio.h>
    #include <stdlib.h>

    struct node
    {
        int num;
        struct node *next;
    };

    void create(struct node **);
    void makecycle(struct node **);
    void release(struct node **);
    int detectcycle(struct node *);

    int main()
    {

        struct node *p = NULL;
        int result;

        printf("Enter data into the list\n");

        create(&p);

        makecycle(&p); 

        printf("Identifying if a cycle exists.\n");

        result = detectcycle(p);

        if (result)

        {

            printf("Cycle detected in the linked list.\n");

        }

        else

        {

            printf("No cycle detected in the linked list.\n");

        }

        release (&p);

        return 0;
    }

    / Make cycles */
    void makecycle(struct node **p)

    {

        struct node *rear, *front;

        int n, count = 0, i;

        front = rear = *p;

        while (rear->next != NULL)

        {

            rear = rear->next;

            count++;

        }

        if (count)

        {

            n = rand() % count;

        }

        else

        {

            n = 1;

        }

        for (i = 0; i < n - 1; i++)

        {

            front = front->next;

        }

        rear->next = front;

        /At this point a cycle is generated in the list/

    }
     

    
    int detectcycle(struct node *head)

    {

        int flag = 1, count = 1, i;

        struct node *p, *q;

     

        p = q = head;

        q = q->next;

        while (1)

        {

            q = q->next;

            if (flag)

            {

                p = p->next;

            }

            if (q == p)

            {

                /Deleting the loop to deallocate the list/

                q = q->next;

                while (q != p)

                {

                    count++;

                    q = q->next;

                }

                q = p = head;

                for (i = 0; i < count; i++)

                {

                    q = q->next;

                }

                while (p != q)

                {

                    p = p->next;

                    q = q->next;

                }

                q->next = NULL;

                return 1;

            }

            else if (q->next == NULL)

            {

                return 0;

            }

            flag = !flag;

        }

    }

    
    

    void create(struct node **head)

    {

        int c, ch;

        struct node *temp, *rear;

        do

        {

            printf("Enter number: ");

            scanf("%d", &c);

            temp = (struct node *)malloc(sizeof(struct node));

            temp->num = c;

            temp->next = NULL;

            if (*head == NULL)

            {

                *head = temp;

            }

            else

            {

                rear->next = temp;

            }

            rear = temp;

            printf("Do you wish to continue [1/0]: ");

            scanf("%d", &ch);

        } while (ch != 0);

        printf("\n");

    }

    
    

    void release(struct node **head)

    {

        struct node *temp = *head;

        temp = temp->next;

        while ((*head) != NULL)

        {

            free(temp);

            temp = *head;

            (*head) = (*head)->next;

        }

    }