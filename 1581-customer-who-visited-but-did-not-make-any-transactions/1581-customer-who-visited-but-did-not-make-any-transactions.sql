# Write your MySQL query statement below
Select V.customer_id,count(V.visit_id) as count_no_trans
from Visits v
LEFT JOIN Transactions t
on v.visit_id = t.visit_id
Where t.transaction_id is NULL
Group BY v.customer_id;