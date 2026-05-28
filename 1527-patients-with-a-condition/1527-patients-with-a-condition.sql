# Write your MySQL query statement below
select patient_id,patient_name,conditions FROM Patients where conditions like "DIAB1%" or
conditions like "% DIAB1%";


-- SELECT 
--     patient_id,
--     patient_name,
--     conditions
-- FROM Patients
-- WHERE conditions LIKE 'DIAB1%'
--    OR conditions LIKE '% DIAB1%';