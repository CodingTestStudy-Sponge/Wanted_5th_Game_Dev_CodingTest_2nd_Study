# 🎮 Wanted 5th Game Dev Coding Test 2nd Study

Wanted 5th Game Dev 코딩테스트 2차 스터디입니다.

각자 서로 다른 코딩테스트 문제를 풀이하고, **Pull Request(PR)를 통해 풀이를 공유한 뒤 대면 스터디에서 서로의 풀이를 설명하고 리뷰하는 것**을 목표로 합니다.

---

## 👥 Members

| GitHub ID        |
| ---------------- |
| `hongsb2334`     |
| `miiiiiiiiiin`   |
| `psin010309-art` |

---

## 🎯 Study Goal

* 코딩테스트 문제 해결 능력 향상
* 다양한 알고리즘 및 풀이 방법 공유
* 다른 사람의 코드를 읽고 리뷰하는 능력 향상
* 시간복잡도와 공간복잡도를 분석하는 습관 형성
* 게임 클라이언트/엔진 개발에 필요한 C++ 문제 해결 능력 향상

---

## 📌 Study Process

각자 **서로 다른 문제를 선택하여 풀이**합니다.

```text
문제 선정
   ↓
문제 풀이
   ↓
PR 생성
   ↓
Project에 PR 등록
   ↓
📝 문제풀이 완료
   ↓
월요일 대면 스터디
   ↓
문제 설명 및 풀이 공유
   ↓
질문 / 의견 / 토론
   ↓
👀 코드 리뷰중
   ↓
PR Review 작성
   ↓
Approve
   ↓
Squash & Merge
   ↓
✅ 리뷰 완료
```

---

## 📋 GitHub Project

스터디 진행 상황은 GitHub Project를 통해 관리합니다.

**Project에는 PR만 등록합니다.**

### Status

| Status     | 의미                        |
| ---------- | ------------------------- |
| 📝 문제푸는 중 | 문제 풀기          |
| 👀 문제풀이 완료  | 문제 풀고 PR 작성 완료 |
| ✅ 리뷰 완료    | 리뷰 및 토론 완료 후 Merge        |

> 문제를 풀기 전 단계는 Project에서 관리하지 않습니다.
> PR을 생성한 시점부터 Project에서 관리합니다.

---

## 🔀 Pull Request

**문제 하나당 하나의 PR을 생성합니다.**

PR은 해당 문제의 풀이와 리뷰 내용을 기록하는 공간입니다.

### PR 제목

```text
[사이트-문제번호] 문제 이름 풀이 완료/미완료
```

예:

```text
[LEETCODE-2094] Finding 3-Digit Even Numbers 풀이 완료
[BOJ-2178] 미로 탐색 풀이 미완료
```

---

## 📝 PR 작성

PR을 생성하면 Repository의 PR Template이 자동으로 적용됩니다.

PR에는 다음 내용을 작성합니다.

* 문제 정보
* 풀이 방법
* 핵심 아이디어
* 시간복잡도
* 공간복잡도
* 리뷰 받고 싶은 부분

---

## 👀 Code Review

코드 리뷰는 **월요일 대면 스터디에서 진행**합니다.

각자 자신의 문제 풀이를 다른 스터디원에게 설명하고, 다음과 같은 내용을 중심으로 의견을 나눕니다.

* 풀이 방법이 적절한지
* 더 효율적인 풀이 방법이 있는지
* 시간복잡도 / 공간복잡도 분석이 맞는지
* 코드에서 개선할 부분이 있는지
* 다른 알고리즘이나 자료구조를 사용할 수 있는지
* 문제를 풀면서 놓친 예외 상황이 있는지

대면에서 나온 **핵심적인 의견과 토론 내용은 PR Review에 기록**합니다.

리뷰의 목적은 반드시 코드를 수정하게 만드는 것이 아니라, 서로의 풀이를 이해하고 더 나은 방법을 함께 고민하는 것입니다.

---

## 🌿 Branch

문제마다 개인 Branch를 생성합니다.

### Branch 이름

```text
<이름>/<사이트>-<문제번호>
```

예:

```text
seongbum/LeetCode-2094
minji/LeetCode-2178
hyeongsin/LeetCode-2667
```

`main` 브랜치에는 직접 Push하지 않습니다.

---

## 💻 Commit

Commit 메시지는 다음 형식을 권장합니다.

문제 사이트 + 문제 번호 + (풀이 완료 or 못품)

예:

```text
LeetCode 2094 풀이 완료
LeetCode 194 못품
```

---

## 📁 Repository Structure

```text
Wanted_5th_Game_Dev_CodingTest_2nd_Study/
│
├── README.md
│
├── .github/
│   └── PULL_REQUEST_TEMPLATE.md
│
└── solutions/
    ├── seongbum/
    │   └── LeetCode-2094/
    │       └── solution.cpp
    ├── minji/
    │   └── LeetCode-316/
    │       └── solution.cpp
    │
    └── hyeongsin/
        └── LeetCode-108/
    │       └── solution.cpp
```

### 문제별 폴더

문제 하나당 하나의 폴더를 생성합니다.

```text
solutions/<이름>/<SITE>_<NUMBER>/
```

예:

```text
solutions/minji/LeetCode-2094/
```

각 문제 폴더에는 다음 파일을 작성합니다.

```text
solution.cpp
```

---

## 자세한 문제 풀이 과정
* 노션 팀스페이스에 정리

---

## 🔒 Main Branch

`main` 브랜치는 보호됩니다.

* 직접 Push 금지
* Pull Request를 통해 Merge
* 다른 스터디원 최소 1명 승인 필요
* Merge는 `Squash and merge` 사용

---

## 📌 Study Rules

1. 각자 문제를 풀이합니다.
2. 문제 하나당 하나의 PR을 생성합니다.
3. 문제마다 개인 Branch를 사용합니다.
4. `main` 브랜치에 직접 Push하지 않습니다.
5. PR 생성 후 Project에 등록합니다.
6. 월요일 대면 스터디에서 자신의 풀이를 설명합니다.
7. 서로 질문하고 풀이에 대한 의견을 나눕니다.
8. 핵심적인 리뷰 내용은 PR Review에 기록합니다.
9. 작성자를 제외한 스터디원 최소 1명의 Approve를 받습니다.
10. Approve 후 `Squash and merge`합니다.
11. Merge가 완료되면 Project 상태를 `리뷰 완료`로 변경합니다.
12. 서로의 풀이와 의견을 존중하며 적극적으로 질문하고 의견을 공유합니다.

---


