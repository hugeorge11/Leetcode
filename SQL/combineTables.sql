SELECT table1.firstName, table1.lastName, table2.city, table2.state
FROM Person table1
LEFT JOIN Address table2
    ON table1.personId = table2.personId;
