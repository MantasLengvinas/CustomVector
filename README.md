# CustomVector

## Ištestuoti metodai

* emplace
* member swap
* non-member swap
* shrink_to_fit
* crend


## CustomVector palyginimas su std::vector

| **std::vector**                             | 10 000    | 100 000 | 1 000 000 | 10 000 000 | 100 000 000 |
| ------------------------------------------- | --------- | ------- | --------- | ---------- | ----------- |
| push_back truko                             | 0.00018s  | 0.0016s | 0.016s    | 0.151s     | 1.433s      |
| Atminties perskirstymų buvo                 | 14        | 17      | 20        | 24         | 27          |

| **CustomVector**                            | 10 000    | 100 000 | 1 000 000 | 10 000 000 | 100 000 000 |
| ------------------------------------------- | --------- | ------- | --------- | ---------- | ----------- |
| push_back truko                             | 0.00015s  | 0.0011s | 0.088s    | 0.119s     | 1.433s      |
| Atminties perskirstymų buvo                 | 13        | 16      | 19        | 23         | 26          |

## Antrosios užduoties std::vector pakeitimo CustomVector rezultatai

| **std::vector**                       | 100 000 |
| ------------------------------------- | ------- |
| Bendras vykdymo laikas                | 1.789s  |

| **CustomVector**                      | 100 000 |
| ------------------------------------- | ------- |
| Bendras vykdymo laikas                | 2.356s  |
