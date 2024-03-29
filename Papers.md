# Introduction

This file contains papers that are interesting. 

## Speech & Language
1. This [SUPERB](https://research.fb.com/wp-content/uploads/2021/08/SUPERB-Speech-Understanding-and-PERformance-Benchmark.pdf) describes pre-training & fine-tuning tasks for speech and downstream tasks such as ASR. The downstream tasks include ASR, speaker id, speaker verification, speaker diarization, emotion recognition, intent detection and slot filling. It shows a baseline setup and has the best performance on slot filling.


## Multi-modality
1. A unified [vision and language model](https://arxiv.org/pdf/2102.02779.pdf) is proposed. Its [git directory](https://github.com/j-min/VL-T5) contains the model. The main idea is using text generation, following BART, to unify all vision and language tasks.

## Interpretation
1. [Neural Additive Machine](https://arxiv.org/pdf/2004.13912.pdf) uses deep neural network to extract prediction on each feature, and the prediction is the sum of each prediction. It has a unique activation function. 
2. [Local Interpretation and Global Interpretation](https://arxiv.org/pdf/2103.12279.pdf) This paper introduces Local Interpretation Layer (LIL) and Global Interpretation Layer (GIL). LIL uses influence method to measure influence from particular non-terminal node of the parsed tree representation of the sentence. GIL uses sentence representation to retrieval the most relevant knowledge/phrase/sampels in training set. LIL and GIL help model performances without sacrificying interpretation capability. I implemented but found the results are not good.
3. https://arxiv.org/pdf/1806.07538.pdf This lays out a general design framework where interpretation can be achieved during model training with regularization that has interpretation concepts. This is a *must* read paper. It is tested on simple image classification tasks. The concept can be applied on more complicated tasks such as natual language processing. 
4. Ues generalized additive model 
(https://www.cs.cornell.edu/~yinlou/papers/lou-kdd12.pdf?spm=ata.21736010.0.0.12c05f3021OdTc&file=lou-kdd12.pdf)
(https://www.cs.cornell.edu/~yinlou/papers/lou-kdd13.pdf?spm=ata.21736010.0.0.12c05f3021OdTc&file=lou-kdd13.pdf)
5. Transformer interpretability 
https://arxiv.org/pdf/2012.09838.pdf This is a good paper to read for its coverage of existing approaches and its proposal. 

6. Explainable Robots
https://arxiv.org/pdf/2105.02658.pdf This is a survey paper on explainable robots. I haven't yet read it thouroughly.

7. Explainable machine learning for medicine
https://arxiv.org/pdf/2105.02357.pdf haven't yet read it. 

8. Debiasing https://assets.amazon.science/2a/60/aff3520f4d52bb195f4a674ae413/debiasing-concept-based-explanations-with-causal-analysis.pdf

9. Piece Linear Neural Network (https://arxiv.org/pdf/1802.06259.pdf)
This method uses a softmax on top of many layers of linear network transformation of inputs. It claims to be exact and better than LIME. However, it best is considered to be linear classification network. LIME is for post-hoc explaination, and this PLNN is not. Also, the feature has been mixed up during PLNN forward computation. So I don't think this method will be inspiring.

10. Interpretable model for ranking from [Google](https://storage.googleapis.com/pub-tools-public-publication-data/pdf/5645c5bd211611898c776e21e83a7f2c0c381c85.pdf). 
The method is solid. It is an intrisically interpretable model. The final model consists of individual neural networks for each feature of an item, and the final output is summation of scores from each of the feature as ![formula](https://render.githubusercontent.com/render/math?math=\hat{y}=\sum_j{f_j(x_j)}). If there are contextual features that are common to all feature items, the context feature contributes to the weight for each feature of an item as ![formula](https://render.githubusercontent.com/render/math?math=\hat{y}_i=\sum_{j=1}^n{w_j(q)f_j(x_{ij})}). The diagram is as ![Screen Shot 2021-05-15 at 9 43 52 AM](https://user-images.githubusercontent.com/3145135/118371581-10e81600-b562-11eb-917b-b338138f470f.png). More importantly, it proposes using piece-wise linear to approximate the neural network output, and call the final model as Distilled Neural Rankder Generalized Additive Model. 

11. [Concept Bottleneck Models](https://arxiv.org/pdf/2007.04612.pdf) 是一个通用的框架。特征必须通过概念（attribute）来解释，再到相对应的标签

12. [Debiasing Concept-based Explanations with Causal Analysis](https://assets.amazon.science/2a/60/aff3520f4d52bb195f4a674ae413/debiasing-concept-based-explanations-with-causal-analysis.pdf) This is a paper needs to read multiple times. It proposes an extension of the graphical model to explain the relation from feature, to concept, and to the label. 
13. [Leveraging Sparse Linear Layers for Debugging Deep Networks](https://arxiv.org/pdf/2105.04857.pdf) this paper proposes using elastic networks with a regularization path to select proper reguarlization with enough interpretability and accuracy. 
14. [Identifiabile attention weights](https://arxiv.org/pdf/2106.01269.pdf) shows that an easy solution is to reduce the size of key vector and increase the length of the value vectors in attention.

## Active Learning
1. Dealing with noise or outlier in Active Learning is studied in the [paper](https://arxiv.org/pdf/2107.02331.pdf) and it suggests using a visualization tool that can show the group biasness of the data. 

## Pretrain
1. New pretrain idea that uses generation tasks for pretraining (https://arxiv.org/pdf/2103.10360.pdf)

## Accuracy and Efficiency Tradeoffs
1. A [length-adaptive transformer](https://arxiv.org/pdf/2010.07003.pdf) is proposed, in which the length at each layer is learned from a teacher. It achieves better accuracy and also lower computational cost, usualy by half, compared to base Bert and distill Bert. 

## Entity Linking and Disabmbiguation
1. This paper proposes a seq-to-seq method to do entity linking, with entities stored as prefix-tree (trie). 
Given the trie, it uses constrained beam-search, which is beam search constrained on the trie. (https://openreview.net/pdf?id=5k8F6UU39V)

## Image Classification using Large Entropy High Dimentional Label
1. (https://openreview.net/pdf?id=MyHwDabUHZm) This idea is to use another modality, such as speech, as the label to the input image. This forces the model to learn a mapping from the original modality of image, to the other modalities. The learned model is observed to be more robust than the model trained with prediction of categorical label distribution. 

![Screen Shot 2021-05-04 at 2 12 29 PM](https://user-images.githubusercontent.com/3145135/117070564-c4d7de80-ace2-11eb-9424-974bfde17028.png)


## Modal architectures
1. [Mlp-mixer](https://arxiv.org/abs/2105.01601) is a production-fiendly model that avoids quardratic computational cost of Transformer. It has mutiple layers of mixer. In each mixer, it rotates a "patch"-wise feature to extract channel-wise feature using an MLP, do rotation and use another MLP to mix the feature back to "patch" wise feature. ![Screen Shot 2021-06-13 at 11 42 00 AM](https://user-images.githubusercontent.com/3145135/121818669-700e7880-cc3d-11eb-93c9-7be42e88d793.png)
2. [Perceiver](https://arxiv.org/pdf/2103.03206.pdf) uses multiple units, with each unit consists of a cross-attention (Q from latent space, K and V are from inputs) to inputs and latent transformers (multiple layers) on the latent space feature. It also applied FFT on the inputs to encode positional information. This FFT can be 1-D for audio/language, 2-D for image, and 3-D for video. Compared to baseline Transformer, its computational cost maybe reduced because latent space dimension can be much smaller than the raw input. It doesn't have information such as through-put as the MLP mixer paper. I am skeptical its results. <img width="1086" alt="Screen Shot 2021-06-13 at 5 32 02 PM" src="https://user-images.githubusercontent.com/3145135/121826667-c85d6e80-cc6d-11eb-9ccd-e0333b03e58f.png">
3. Supporting interpretable and robust models (https://arxiv.org/pdf/2102.07048.pdf) implies that the model needs to output prediction at each iteration and a risk score is a summation of all the predictions. 

 
## Logics and Entailment

1. https://arxiv.org/pdf/1802.08535.pdf

The idea of PossibleWorldNet incorporates sampled words and use them to evaluate an entailment. The score is then used as feature or directly used for prediction entailment. Adding possible words is a strong *grounding" process, as that can encode human knowledge into it. 

## Sequence Labeling
1. Tagging via Masked CRF https://arxiv.org/pdf/2103.10682.pdf
This paper seems solve the illegal tagging problem in a fundamental yet simple way. It masks the illegal paths with a large negative score in both training and inference. 

## Self-supervised Learning
1. Yann Lecun's [blog](https://ai.facebook.com/blog/self-supervised-learning-the-dark-matter-of-intelligence/) emphasized importance of self-supervised learning, in which less transcription is an advantage of this approach. For vision, as there is no vocabulary, it is hard to associate reconstruction with certainty&dimension - CV has infinite uncertainty. Therefore, for CV, it proposes an energey based method of contrastive learning, which uses a scalar value to describe how x and y fit each other. For example, the energy function can be a L2 norm. It suggests an architecture of using regualarized latent variable to generate unlimited amount of perturbations of the original data, and then use contrastive method to learn a good representation of the original input. The representation will be used in downstream supervised learning tasks.

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


## Reinforcement Learning
1. [Reinforcement Learning as a Sequence Modeling Problem](https://arxiv.org/pdf/2106.02039.pdf) is an interesting paper. It essentially quantizes trajectory with each time sample quantized to a token that has a certain vocabulary. These tokens are then used similarly as those used with Transformer-type modeling. The output for reinforcement learning can be prediction of action. 
2. [Decision Transformer](https://arxiv.org/abs/2106.01345) Can be any sequence model, and not necessarily a transformer. It has an input of expected reward and state. It outputs a prediction of the action that should achieve this reward. This paper is similar to the Upside Down RL from Schmidhubert. ![action prediction](https://latex.codecogs.com/svg.latex?a_t=\theta(\hat{R}_t,s_t)) The expected reward can be obtained from future data. It therefore constructs the following trajectory representation, which is amenable to autoregressive training and generation: ![trajectory](https://latex.codecogs.com/svg.latex?r=\left(\hat{R}_1,s_1,a_1,\hat{R}_2,s_2,a_2,\cdots,\hat{R}_T,S_T,a_T\right).), in which the reward is defined as ![reward](https://latex.codecogs.com/svg.latex?\hat{R}_k=\sum_{t=k}^Tr_k).

## Dataset

1. GLUE dataset

https://gluebenchmark.com/tasks

