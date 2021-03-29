# Introduction

This file contains papers that are interesting. 

## Interpretation
1. https://arxiv.org/pdf/2103.12279.pdf 
This paper introduces Local Interpretation Layer (LIL) and Global Interpretation Layer (GIL). LIL uses influence method to measure influence from particular non-terminal node of the parsed tree representation of the sentence. GIL uses sentence representation to retrieval the most relevant knowledge/phrase/sampels in training set. LIL and GIL help model performances without sacrificying interpretation capability.

2. https://arxiv.org/pdf/1806.07538.pdf 
Interpretation on CV tasks.


## Pretrain
1. New pretrain idea that uses generation tasks for pretraining (https://arxiv.org/pdf/2103.10360.pdf)

## Logics and Entailment

1. https://arxiv.org/pdf/1802.08535.pdf

The idea of PossibleWorldNet incorporates sampled words and use them to evaluate an entailment. The score is then used as feature or directly used for prediction entailment. Adding possible words is a strong *grounding" process, as that can encode human knowledge into it. 

## Sequence Labeling
1. Tagging via Masked CRF https://arxiv.org/pdf/2103.10682.pdf
This paper seems solve the illegal tagging problem in a fundamental yet simple way. It masks the illegal paths with a large negative score in both training and inference. 

## Continual Learning
### Study on Multi-modal models
1. This paper proposes a new dataset for the study of the continual learning on multi-modal systems. (https://arxiv.org/pdf/2005.00785.pdf)

## Image&Text Grammar Induction
1. https://arxiv.org/pdf/2103.12975.pdf
This paper is interesting. It provides a dataset that has an alignment between image parts and text grammar. Both grammars use PCFG. However, the positional information is lost in the image grammar. 

## Multimodal Disinformation Detection
1. https://arxiv.org/pdf/2103.12541.pdf
This paper is related to extract disinformation from many sources. Hoewver, it points out that interpretibility, common-sense reasoning as important prior knoweldge to use. It cannot just rely on the content signals. 

## Overview paper for conversational agent 

1. https://arxiv.org/pdf/1803.08419.pdf

This is a summary of the up-to-date work on conversational agent. I especially like the discussion of incorporating knowledge into conversational agent, aka. grounding. One method is using a ngram from query to link common sense knoweledge, from which a neural network model generates responses informatively. 

2. https://arxiv.org/pdf/2103.10518.pdf

This paper uses noisy-channel model, so that each component can be seperately pretrained and fine-tuned. The architecture allows individual and overall tuning to optimize performances. 

## Edge Device

1. Text classification and sentence-level classification model on server-less. However, the model is still too large with 200M byte. ( https://arxiv.org/pdf/2103.10673.pdf)

