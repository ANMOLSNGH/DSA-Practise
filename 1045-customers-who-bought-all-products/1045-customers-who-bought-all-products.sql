# Write your MySQL query statement below
Select c.customer_id 
from Customer c
Group By c.customer_id
HAVING COUNT(DISTINCT c.product_key) = (
    Select COUNT(DISTINCT(p.product_key))
    from Product p
);