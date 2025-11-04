# CS221 Project: Vietnamese Named Entity Recognition using PhoBERT

This project implements a Named Entity Recognition (NER) system for the Vietnamese language using the [PhoBERT](https://huggingface.co/VinAI/phobert-base) pre-trained model.

## 📌 Project Objective

The main goal is to build a robust NER model for Vietnamese text, identifying entities such as **locations (LOC)**, **persons (PER)**, and **organizations (ORG)**. We fine-tune a pre-trained PhoBERT model on a Vietnamese NER dataset following the IOB2 labeling scheme.

## 🗃️ Dataset

We use the [WikiANN](https://huggingface.co/datasets/wikiann) dataset for Vietnamese, which contains token-level annotations in the IOB2 format for common named entity types.

## 🛠️ Features

- Token classification using PhoBERT
- Support for IOB2 tagging
- Metric computation: F1-score
