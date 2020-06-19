![Build](https://github.com/GaryHughes/crocofix/workflows/Build/badge.svg)

# CrocoFIX

CrocoFIX is a C++ implementation of the [FIX protocol](https://www.fixtrading.org/online-specification/). CrocoFIX contains a rich data dictionary generated from the [FIX Orchestra standard](https://www.fixtrading.org/standards/fix-orchestra/).

1. [Intent](#intent)
1. [Requirements](#requirements)
1. [Orchestrations](#orchestrations)
1. [Performance](#performance)
1. [Components](#components)
    1. [Lexicographer](#lexicographer)
    1. [libcrocofixdictionary](#libcrocofixdictionary)
    1. [libcrocofix](#libcrocofix)
1. [Utilities](#utilities)
    1. [fixcat](#fixcat)
    1. [fixsed](#fixsed)
1. [Examples](#examples)
    1. [acceptor](#acceptor)
    1. [initiator](#initiator)

# Intent

I use this code base as a playground for current C++ features and so have no intent to provide or maintain compatability with older language standards and I will move to newer standards as they become generally available.

# Requirements

CrocoFIX currently requires a C++ 17 compiler. It is built and tested on macOS with Apple Clang from the latest Xcode and on Ubuntu with Clang 10.

The only current external dependency is [Boost](https://boost.org)

Check the supplied [Dockerfile](https://github.com/GaryHughes/crocofix/blob/master/Dockerfile) for detailed build requirements. This is the environment used to build in Github Actions [here](https://github.com/GaryHughes/crocofix/actions?query=workflow%3ABuild).

# Orchestrations

This contains a selection of the orchestrations provided by the FIX Trading Community [here](https://github.com/FIXTradingCommunity/orchestrations). These are used by the lexicographer to generate content compiled into libcrocofixdictionary. The lexicographer can also be used to generate code for any other valid orchestration and this can be included in your own libraries and executables.

# Performance

[Performance](https://github.com/GaryHughes/crocofix/blob/main/performance/README.md)

# Components

## lexicographer

The lexicographer is a set of [Python](https://python.org) scripts that parses the orchestration XML and generates a set of classes to allow for easy consumption of the orchestration metdata in C++ programs. Details can be found [here](https://github.com/GaryHughes/crocofix/blob/master/lexicographer/README.md). The generated class rely on common code in libcrocofixdictionary.

## libcrocofixdictionary

This contains common code used by the classes generated by the lexicographer and is the container for the generated code.

## libcrocofix

This contains general FIX functionality such as parsing and message construction. This code relies on libcrocofixdictionary.

# Utilities

## fixcat

fixcat is modelled on the UNIX cat utility; it will print FIX messages in human readable format with message, field, and enumerated value descriptions. See [here](https://github.com/GaryHughes/crocofix/blob/main/fixcat/README.md) for details.

## fixsed

# Examples

## Acceptor

This is a minimal FIX server application that will accept socket connects and will respond to any NewOrderSingles sent to it with an ExecutionReport ACK.

## Initiator

This is a minimal FIX client application that will connect to a FIX server, send NewOrderSingles and wait for ExecutionReport ACK messages.

# Acknowledgements

This repository includes orchestrations published by www.fixtrading.org Copyright (c) FIX Protocol Ltd. All Rights Reserved.