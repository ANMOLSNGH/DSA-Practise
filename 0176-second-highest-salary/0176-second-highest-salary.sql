# Write your MySQL query statement below
Select (
    select distinct salary
    from Employee
    ORDER BY salary DESC
    LIMIT 1 OFFSET 1
) As SecondHighestSalary;
