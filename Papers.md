# Introduction

This file contains papers that are interesting. 

## Interpretation
1. https://arxiv.org/pdf/2103.12279.pdf 
*Excellent paper* This paper introduces Local Interpretation Layer (LIL) and Global Interpretation Layer (GIL). LIL uses influence method to measure influence from particular non-terminal node of the parsed tree representation of the sentence. GIL uses sentence representation to retrieval the most relevant knowledge/phrase/sampels in training set. LIL and GIL help model performances without sacrificying interpretation capability.

2. https://arxiv.org/pdf/1806.07538.pdf 
This lays out a general design framework where interpretation can be achieved during model training with regularization that has interpretation concepts. 
This is a *must* read paper. It is tested on simple image classification tasks. The concept can be applied on more complicated tasks such as natual language processing. 

3. Ues generalized additive model 
(https://www.cs.cornell.edu/~yinlou/papers/lou-kdd12.pdf?spm=ata.21736010.0.0.12c05f3021OdTc&file=lou-kdd12.pdf)
(https://www.cs.cornell.edu/~yinlou/papers/lou-kdd13.pdf?spm=ata.21736010.0.0.12c05f3021OdTc&file=lou-kdd13.pdf)

4. Transformer interpretability 
https://arxiv.org/pdf/2012.09838.pdf This is a good paper to read for its coverage of existing approaches and its proposal. 

5. Explainable Robots
https://arxiv.org/pdf/2105.02658.pdf This is a survey paper on explainable robots. I haven't yet read it thouroughly.

6. Explainable machine learning for medicine
https://arxiv.org/pdf/2105.02357.pdf haven't yet read it. 

7. Debiasing https://assets.amazon.science/2a/60/aff3520f4d52bb195f4a674ae413/debiasing-concept-based-explanations-with-causal-analysis.pdf

8. Piece Linear Neural Network (https://arxiv.org/pdf/1802.06259.pdf)
This method uses a softmax on top of many layers of linear network transformation of inputs. It claims to be exact and better than LIME. However, it best is considered to be linear classification network. LIME is for post-hoc explaination, and this PLNN is not. Also, the feature has been mixed up during PLNN forward computation. So I don't think this method will be inspiring.

9. Interpretable model for ranking from [Google](https://storage.googleapis.com/pub-tools-public-publication-data/pdf/5645c5bd211611898c776e21e83a7f2c0c381c85.pdf). 
The method is solid. It is an intrisically interpretable model. The final model consists of individual neural networks for each feature of an item, and the final output is summation of scores from each of the feature as ![formula](https://render.githubusercontent.com/render/math?math=\hat{y}=\sum_j{f_j(x_j)}). If there are contextual features that are common to all feature items, the context feature contributes to the weight for each feature of an item as ![formula](https://render.githubusercontent.com/render/math?math=\hat{y}_i=\sum_{j=1}^n{w_j(q)f_j(x_{ij})}). The diagram is as ![Screen Shot 2021-05-15 at 9 43 52 AM](https://user-images.githubusercontent.com/3145135/118371581-10e81600-b562-11eb-917b-b338138f470f.png). More importantly, it proposes using piece-wise linear to approximate the neural network output, and call the final model as Distilled Neural Rankder Generalized Additive Model. 


## Pretrain
1. New pretrain idea that uses generation tasks for pretraining (https://arxiv.org/pdf/2103.10360.pdf)

## Entity Linking and Disabmbiguation
1. This paper proposes a seq-to-seq method to do entity linking, with entities stored as prefix-tree (trie). 
Given the trie, it uses constrained beam-search, which is beam search constrained on the trie. (https://openreview.net/pdf?id=5k8F6UU39V)

## Image Classification using Large Entropy High Dimentional Label
1. (https://openreview.net/pdf?id=MyHwDabUHZm) This idea is to use another modality, such as speech, as the label to the input image. This forces the model to learn a mapping from the original modality of image, to the other modalities. The learned model is observed to be more robust than the model trained with prediction of categorical label distribution. 

![Screen Shot 2021-05-04 at 2 12 29 PM](https://user-images.githubusercontent.com/3145135/117070564-c4d7de80-ace2-11eb-9424-974bfde17028.png)


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

## Tree-structure Models
1. Recursive Transformer with CKY-style computing. Title: R2D2: Recursive Transformer based on Differentiable Treesfor Interpretable Hierarchical Language Modeling, ACL-2021. 

This paper proposed a tree-structure model. 
![Screen Shot 2021-05-14 at 11 25 37 AM](https://user-images.githubusercontent.com/3145135/118313056-1e8c9580-b4a7-11eb-8d58-3ce4f4d44c34.png)

To reduce computational costs from O(N^3), it proposes a pruning method with cost of O(N). Also it proposes a pre-training task to predict a word given left- and right-context with tree-structure induction.

## Overview paper for conversational agent 

1. https://arxiv.org/pdf/1803.08419.pdf

This is a summary of the up-to-date work on conversational agent. I especially like the discussion of incorporating knowledge into conversational agent, aka. grounding. One method is using a ngram from query to link common sense knoweledge, from which a neural network model generates responses informatively. 

2. https://arxiv.org/pdf/2103.10518.pdf

This paper uses noisy-channel model, so that each component can be seperately pretrained and fine-tuned. The architecture allows individual and overall tuning to optimize performances. 

## Edge Device

1. Text classification and sentence-level classification model on server-less. However, the model is still too large with 200M byte. ( https://arxiv.org/pdf/2103.10673.pdf)


## Dataset

1. GLUE dataset

https://gluebenchmark.com/tasks


