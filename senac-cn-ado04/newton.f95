PROGRAM NEWTON
    IMPLICIT NONE
    REAL :: p
    REAL :: xi
    REAL :: xf
    REAL :: error = 0.00000001
    INTEGER :: i
    READ*, p 
    xi = p
    DO WHILE (i < 40)
        xf = xi - (((xi*Xi) - p) / (2*xi))
        IF(abs(xi - xf) < error) THEN
            EXIT
        END IF
        xi = xf
        i = i + 1
    END DO
    PRINT*, xi
END PROGRAM NEWTON