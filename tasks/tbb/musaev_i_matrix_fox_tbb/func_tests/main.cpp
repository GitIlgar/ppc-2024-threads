// Copyright 2024 Musaev Ilgar
#include <gtest/gtest.h>
#include <tbb/tbb.h>

#include <iostream>
#include <vector>

#include "tbb/musaev_i_matrix_fox_tbb/include/musaev_i_tbb.h"

TEST(Musaev_I_Mult_Matrix_Fox, validationTest) {
  size_t n = 2;
  std::vector<double> in1{2.0, 5.0, 3.0, -1.0};
  std::vector<double> in2{1.0, 0.0, 0.0, 1.0};
  std::vector<double> out(n * n);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in1.data()));
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in2.data()));
  taskDataSeq->inputs_count.emplace_back(in1.size());
  taskDataSeq->inputs_count.emplace_back(in2.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  MusaevFoxAlgTaskTBB musaevTask(taskDataSeq);
  ASSERT_EQ(musaevTask.validation(), true);
}

TEST(Musaev_I_Mult_Matrix_Fox, mult2) {
  size_t n = 10;
  std::vector<double> in1(n * n, 10.0);
  std::vector<double> in2(n * n, 1.0);
  std::vector<double> out(n * n, 0.0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in1.data()));
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in2.data()));
  taskDataSeq->inputs_count.emplace_back(in1.size());
  taskDataSeq->inputs_count.emplace_back(in2.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  MusaevFoxAlgTaskTBB musaevTask(taskDataSeq);
  ASSERT_EQ(musaevTask.validation(), true);
  ASSERT_TRUE(musaevTask.pre_processing());
  ASSERT_TRUE(musaevTask.run());
  ASSERT_TRUE(musaevTask.post_processing());

  std::vector<double> expected_result = mulMusaev(in1, in2, n);

  double epsilon = 1e-6;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      EXPECT_NEAR(out[i * n + j], expected_result[i * n + j], epsilon);
    }
  }
}

TEST(Musaev_I_Mult_Matrix_Fox, mult3) {
  size_t n = 10;
  std::vector<double> in1(n * n, 10.0);
  std::vector<double> in2(n * n, 10.0);
  std::vector<double> out(n * n);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in1.data()));
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in2.data()));
  taskDataSeq->inputs_count.emplace_back(in1.size());
  taskDataSeq->inputs_count.emplace_back(in2.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  MusaevFoxAlgTaskTBB musaevTask(taskDataSeq);
  ASSERT_EQ(musaevTask.validation(), true);
  ASSERT_TRUE(musaevTask.pre_processing());
  ASSERT_TRUE(musaevTask.run());
  ASSERT_TRUE(musaevTask.post_processing());

  std::vector<double> expected_result = mulMusaev(in1, in2, n);

  double epsilon = 1e-6;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      EXPECT_NEAR(out[i * n + j], expected_result[i * n + j], epsilon);
    }
  }
}

TEST(Musaev_I_Mult_Matrix_Fox, mult4) {
  size_t n = 4;
  std::vector<double> in1{1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0, 17.0, 19.0, 21.0, 23.0, 25.0, 27.0, 29.0, 31.0};
  std::vector<double> in2{2.0,     6.0,     18.0,     54.0,     162.0,     486.0,     1458.0,    4374.0,
                          13122.0, 39366.0, 118098.0, 354294.0, 1062882.0, 3188646.0, 9565938.0, 28697814.0};
  std::vector<double> out(n * n, 0.0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in1.data()));
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in2.data()));
  taskDataSeq->inputs_count.emplace_back(in1.size());
  taskDataSeq->inputs_count.emplace_back(in2.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  MusaevFoxAlgTaskTBB musaevTask(taskDataSeq);
  ASSERT_EQ(musaevTask.validation(), true);
  ASSERT_TRUE(musaevTask.pre_processing());
  ASSERT_TRUE(musaevTask.run());
  ASSERT_TRUE(musaevTask.post_processing());

  std::vector<double> expected_result = mulMusaev(in1, in2, n);

  double epsilon = 1e-6;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      EXPECT_NEAR(out[i * n + j], expected_result[i * n + j], epsilon);
    }
  }
}

TEST(Musaev_I_Mult_Matrix_Fox, mult5) {
  size_t n = 4;
  std::vector<double> in1{1.0, 2.0, 3.0, 4.0, 2.0, 3.0, 4.0, 5.0, 3.0, 4.0, 5.0, 6.0, 4.0, 5.0, 6.0, 7.0};
  std::vector<double> in2{10.0, 9.0, 8.0, 7.0, 9.0, 8.0, 7.0, 6.0, 8.0, 7.0, 6.0, 5.0, 7.0, 6.0, 5.0, 4.0};
  std::vector<double> out(n * n, 0.0);

  std::shared_ptr<ppc::core::TaskData> taskDataSeq = std::make_shared<ppc::core::TaskData>();
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in1.data()));
  taskDataSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(in2.data()));
  taskDataSeq->inputs_count.emplace_back(in1.size());
  taskDataSeq->inputs_count.emplace_back(in2.size());
  taskDataSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(out.data()));
  taskDataSeq->outputs_count.emplace_back(out.size());

  MusaevFoxAlgTaskTBB musaevTask(taskDataSeq);
  ASSERT_EQ(musaevTask.validation(), true);
  ASSERT_TRUE(musaevTask.pre_processing());
  ASSERT_TRUE(musaevTask.run());
  ASSERT_TRUE(musaevTask.post_processing());

  std::vector<double> expected_result = mulMusaev(in1, in2, n);

  double epsilon = 1e-6;
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      EXPECT_NEAR(out[i * n + j], expected_result[i * n + j], epsilon);
    }
  }
}
