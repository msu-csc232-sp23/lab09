# LAB09 - Exploring List Implementations

In today's lab, we explore and further define methods in the `ArrayList` and `LinkedList` ADTs.

## Background

Before proceeding with this lab, the student should take the time to read

* [Chapter 8 - Lists](https://bookshelf.vitalsource.com/reader/books/9780134477473/epubcfi/6/188%5B%3Bvnd.vst.idref%3DP7001011925000000000000000002728%5D!/4/2%5BP7001011925000000000000000002728%5D/4%5BP700101192500000000000000000272B%5D/4%5BP700101192500000000000000000AC2C%5D/2/2%5BP700101192500000000000000000AC2D%5D/1:0%5B%2CPre%5D)
* [Chapter 9 - List Implementations](https://bookshelf.vitalsource.com/reader/books/9780134477473/epubcfi/6/202%5B%3Bvnd.vst.idref%3DP700101192500000000000000000295E%5D!/4/2%5BP700101192500000000000000000295E%5D/4%5BP7001011925000000000000000002961%5D/2%5BP700101192500000000000000000AE09%5D/4%5BP700101192500000000000000000AE0B%5D/2%5BP700101192500000000000000000AE0C%5D/4%5BP700101192500000000000000000AE14%5D/4%5BP700101192500000000000000000AE16%5D)
* Section 1.5.6 (The Big-Five) in the Weiss Textbook (accessible via Microsoft Teams Class Materials)

As you navigate your way through this code base, you may find some new C++ syntactical features that you may not have seen before.

### C++11 Feature - The proper way to declare exceptions are possibly thrown

When our textbook introduced us to the idea of methods throwing exceptions, the authors utilized an older, outdated, method to indicate this fact. For example,

```c++
ItemType getEntry(int position) const throw(PrecondViolatedExcep)
```

However, this project is configured (by `cmake`) to use the C++17 standard. As a result, the above code (which is syntactically correct), generates the following error (or at least, a warning):

```text
ISO C++17 does not allow dynamic exception specifications
```

This is telling you to update your syntax. For myriad reasons, support for the above syntax was difficult. The C++ language has moved to a new, simpler, way of annotating our code to indicate that it _may_ throw an exception. We instead use, `noexcept(false)` as shown below:

```c++
ItemType getEntry(int position) const noexcept(false)
```

The way to read this, is to understand negative logic. The `noexcept` is kind of like a statement that says, I'm not throwing an exception... but we add the `false` argument to this, and it reads "It is false that I'm not throwing any exceptions." Said another way, I may throw an exception if warranted. This manner of expression was introduced in C++11, but its usage is forced upon us in C++17 and higher.

### C++17 Feature - C++ Attributes

Another syntactical device you'll see scattered throughout the code is the use of the `nodiscard` attribute. Essentially, we tack this onto any method that we want to ensure is being used properly. For example, accessor methods return values. If we annotate an accessor with this attribute, we're forcing the IDE to warn us if calls are made to this accessor method but the values are simply ignored (e.g., not assigned to a variable).

To learn more about this attribute, see this [info on nodiscard](https://en.cppreference.com/w/cpp/language/attributes/nodiscard).

## Objectives

Upon successful completion of this lab, the student has demonstrated their ability to

* define an initializing constructor that initializes an ArrayList with an array of data
* define the replace method in the LinkedList class
* define the copy constructor in the LinkedList class

## Getting Started

After accepting this assignment with the provided [GitHub Classroom Assignment link](https://classroom.github.com/a/2oni8d_1), clone this repository. If you have cloned the repository from the command line prompt, navigate into the newly created directory

```bash
cd lab09-github-username
```

Next, create a branch named `develop`. Please note: The name of this branch **must** be as specified and will be, to the grading scripts, case-sensitive.

```bash
git checkout -b develop
```

Make sure you are on the `develop` branch before you get started. Make all your commits on the `develop` branch.

```bash
git status
```

_You may have to type the `q` character to get back to the command line prompt after viewing the status._

## Tasks

This lab consists of three tasks:

- Task 1: Add an initializing constructor to the ArrayList
- Task 2: Define the method replace for the class LinkedList
- Task 3: Define the copy constructor for the class LinkedList

### Task 1: Add an initializing constructor to the ArrayList

In this first task, we'll be modifying the `ArrayList` class. We will add an _initializing constructor_ that is used to create a new List based upon an array of items. One caveat to look out for is whether the array is too big to place in the `ArrayList`. In the event that we attempt to initialize an `ArrayList` with an array that is bigger than its capacity, is to simply fill it to capacity and ignore the rest of the array items.

1. Toggle the `TEST_TASK1` macro (found in the [csc232.h](include/csc232.h) header file) from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 1.2` found in the [ArrayList.h](include/ArrayList.h) header file and follow its instructions.
3. Locate the `TODO: Task 1.3` found in the [ArrayList.cpp](src/main/cpp/ArrayList.cpp) source file and define this new constructor, keeping in mind the above caveat.
4. Execute the `google-tests` target (or `ctest`) to validate your work.
5. Once the unit tests for this task pass, commit your changes and push them to GitHub.

### Task 2: Define the method replace for the class LinkedList

1. Toggle the `TEST_TASK2` macro (found in the [csc232.h](include/csc232.h) header file) from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 2.2` found in the [LinkedList.h](include/LinkedList.h) header file and follow its instructions. Be sure to include the `@throw` tag to indicate the conditions under which an exception would occur and what exception is thrown as a result.
3. Locate the `TODO: Task 2.3` found in the [ArrayList.cpp](src/main/cpp/LinkedList.cpp) source file and define this method.
4. Execute the `google-tests` target (or `ctest`) to validate your work.
5. Once the unit tests for this task pass, commit your changes and push them to GitHub.

### Task 3: Define the copy constructor for the class LinkedList

1. Toggle the `TEST_TASK3` macro (found in the [csc232.h](include/csc232.h) header file) from `FALSE` to `TRUE`.
2. Locate the `TODO: Task 3.2` found in the [LinkedList.h](include/LinkedList.h) header file and follow its instructions.
3. Locate the `TODO: Task 3.3` found in the [ArrayList.cpp](src/main/cpp/LinkedList.cpp) source file and define this constructor.
4. Execute the `google-tests` target (or `ctest`) to validate your work.
5. Once the unit tests for this task pass, commit your changes and push them to GitHub.

## Submission Details

Before submitting your assignment, be sure you have pushed all your changes to GitHub. If this is the first time you're pushing your changes, the push command will look like:

```bash
git push -u origin develop
```

If you've already set up remote tracking (using the `-u origin develop` switch), then all you need to do is type

```bash
git push
```

As usual, prior to submitting your assignment on Microsoft Teams, be sure that you have committed and pushed your final changes to GitHub. Once your final changes have been pushed, create a pull request that seeks to merge the changes in your `develop` branch into your `trunk` branch. Once your pull request has been created, submit the URL of your assignment _repository_ (i.e., _not_ the URL of the pull request) as a Link Resource on Microsoft Teams. Please note: the timestamp of the submission on Microsoft Teams is used to assess any late penalties if and when warranted, _not_ the date/time you create your pull request. **No exceptions will be granted for this oversight**.

### Due Date

Your assignment submission is due by 11:59 PM, April 22, 2023.

### Grading Rubric

This assignment is worth **3 points**.

| Criteria           | Exceeds Expectations         | Meets Expectations                  | Below Expectations                  | Failure                                        |
|--------------------|------------------------------|-------------------------------------|-------------------------------------|------------------------------------------------|
| Pull Request (20%) | Submitted early, correct url | Submitted on-time; correct url      | Incorrect URL                       | No pull request was created or submitted       |
| Code Style (20%)   | Exemplary code style         | Consistent, modern coding style     | Inconsistent coding style           | No style whatsoever or no code changes present |
| Correctness^ (60%) | All unit tests pass          | At least 80% of the unit tests pass | At least 60% of the unit tests pass | Less than 50% of the unit tests pass           |

^ _The Google Test unit runner will calculate the correctness points based purely on the fraction of tests passed_.

### Late Penalty

* In the first 24-hour period following the due date, this lab will be penalized 0.6 point meaning the grading starts at 2.4 (out of 3 total possible) points.
* In the second 24-hour period following the due date, this lab will be penalized 1.2 points meaning the grading starts at 1.8 (out of 3 total possible) points.
* After 48 hours, the assignment will not be graded and thus earns no points, i.e., 0 out of 3 possible points.
